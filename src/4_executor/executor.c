/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:07:10 by awillems          #+#    #+#             */
/*   Updated: 2022/06/30 12:37:17 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int		exe_build_in(char *cmd, char **args, char **envp);
void	exe_file(char *cmd, char **args, char **envp);
void	exe_normal(char *cmd, char **args, char **envp);
void	set_fd_to_std(int fd, int output);

void	print_cmd(char *cmd, char **args)
{
	int	i;

	if (!DEBUG_PRINT)
		return ;
	printf("%s: [", cmd);
	i = 0;
	while (args[i])
		printf("%s, ", args[i++]);
	printf("]\n");
}

void	execute_cmd(size_t i, char *cmd, char **args, char **envp)
{
	print_cmd(cmd, args);
	if (get_instr(i)->err != 0)
	{
		fprintf(stderr, "%s: %s\n", g_data.cmd, strerror(get_instr(i)->err));
		exit(get_instr(i)->err);
	}
	set_fd_to_std(get_instr(i)->fds[0], STDIN_FILENO);
	set_fd_to_std(get_instr(i)->fds[1], STDOUT_FILENO);
	if (cmd && (cmd[0] == '/' || cmd[0] == '.'))
		exe_file(cmd, args, envp);
	else if (exe_build_in(cmd, args, envp))
		;
	else
	{
		exe_normal(cmd, args, envp);
		fprintf(stderr, "%s: %s\n", g_data.cmd, "command not found");
		exit(EX_NOTFOUND);
	}
	exit(0);
}

void	line_executor(void)
{
	pid_t	pid;
	int		status;
	size_t	i;

	print_debug_sep("EXECUTION");
	i = 0;
	while (i < get_instr_list()->len)
	{
		if (get_instr(i)->type == 1)
		{
			pid = fork();
			if (pid == 0)
				execute_cmd(i,
					get_instr_arg_elem(i, 0),
					get_instr_arg(i)->buffer,
					NULL);
			vec_delete(&g_data.tmp);
		}
		i++;
	}
	waitpid(pid, &status, 0);
	g_data.last_exit_code = WEXITSTATUS(status);
	print_debug_sep("END");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:07:10 by awillems          #+#    #+#             */
/*   Updated: 2022/06/28 09:12:38 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int		exe_build_in(char *cmd, char **args, char **envp);
void	exe_normal(char *cmd, char **args, char **envp);
void	set_fd_to_std(int fd, int output);

// void	print_cmd(size_t i)
// {
// 	if (!DEBUG_PRINT)
// 		return ;
// 	size_t j = 0;
// 	printf("%d => [%s", get_instr(i)->fds[0], get_instr_arg_elem(i, j));
// 	j++;
// 	while (j < get_instr_arg(i)->content_len)
// 		printf(", %s", get_instr_arg_elem(i, j++));
// 	printf("] => %d\n", get_instr(i)->fds[1]);
// }

void	print_cmd(char *cmd, char **args)
{
	if (!DEBUG_PRINT)
		return ;
	printf("%s: [", cmd);
	int i = 0;
	while (args[i])
	{
		printf("%s, ", args[i]);
		i++;
	}
	printf("]\n");
}


void	execute_cmd(size_t i)
{
	char	**envp = NULL;
	char	**args = get_instr_arg(i)->buffer;
	char	*cmd = get_instr_arg_elem(i, 0);

	printf("%lu %lu\n", get_instr_arg(i)->content_len, get_instr_arg(i)->len);
	vec_print(get_instr_arg(i));
	print_cmd(cmd, args);
	if (get_instr(i)->err != 0)
	{
		fprintf(stderr, "%s: %s\n", g_data.cmd, strerror(get_instr(i)->err));
		exit(get_instr(i)->err);
	}
	set_fd_to_std(get_instr(i)->fds[0], STDIN_FILENO);
	set_fd_to_std(get_instr(i)->fds[1], STDOUT_FILENO);
	if (cmd && (cmd[0] == '/' || cmd[0] == '.'))
	{
		execve(cmd, args, envp);
		fprintf(stderr, "%s: %s\n", g_data.cmd, strerror(errno));
		exit(EX_NOTFOUND);
	}
	else if (exe_build_in(cmd, args, envp))
		exit(0);
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

	if (DEBUG_PRINT)
		printf("\e[0;36m0=====-----	EXECUTION	-----=====0\n\e[0m");
	for (size_t i = 0; i < get_instr_list()->content_len; i++)
	{
		if (get_instr(i)->type == 1)
		{
			pid = fork();
			if (pid == 0)
				execute_cmd(i);
			waitpid(pid, &status, 0);
			vec_delete(&g_data.tmp);
			g_data.last_exit_code = WEXITSTATUS(status);
		}
	}
	if (DEBUG_PRINT)
		printf("\e[0;36m0=====-----	END		-----=====0\n\e[0m");
}

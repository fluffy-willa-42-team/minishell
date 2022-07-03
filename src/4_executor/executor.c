/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:07:10 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 09:03:17 by mahadad          ###   ########.fr       */
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

void	set_fd_to_std(int fd[2], int input, int output)
{
	if (fd[0] != input)
	{
		dup2(fd[0], input);
		close(fd[0]);
	}
	if (fd[1] != output)
	{
		dup2(fd[1], output);
		close(fd[1]);
	}
}

void	close_fd_pipe(int fd[2])
{
	if (fd[0] != STDIN_FILENO)
		close(fd[0]);
	if (fd[1] != STDOUT_FILENO)
		close(fd[1]);
}

void	print_cmd(char *cmd, char **args)
{
	int	i;

	if (!DEBUG_PRINT)
		return ;
	printf("[%s", cmd);
	i = 1;
	while (args[i])
		printf(", %s", args[i++]);
	printf("]\n");
}

void	execute_cmd(size_t i, char *cmd, char **args, char **envp)
{
	print_cmd(cmd, args);
	if (get_instr(i)->err != 0)
	{
		fprintf(stderr, "%s: %s\n", g_data.cmd, strerror(get_instr(i)->err));//TODO FIX function not allowd
		exit(get_instr(i)->err);
	}
	set_fd_to_std(get_instr(i)->fds, STDIN_FILENO, STDOUT_FILENO);
	if (cmd && (cmd[0] == '/' || cmd[0] == '.'))
		exe_file(cmd, args, envp);
	// else if (exe_build_in(cmd, args, envp))
	// 	;//WIP moved to line_executor @willa check if this not affect your logic.
	else
	{
		exe_normal(cmd, args, envp);
		fprintf(stderr, "%s: %s\n", g_data.cmd, "command not found");//TODO FIX function not allowd
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
			if (!exe_build_in(get_instr_arg_elem(i, 0),
					get_instr_arg(i)->buffer,
					g_data.env.buffer))
			{
				pid = fork();
				if (pid == 0)
					execute_cmd(i,
						get_instr_arg_elem(i, 0),
						get_instr_arg(i)->buffer,
						g_data.env.buffer);
				close_fd_pipe(get_instr(i)->fds);
				vec_delete(&g_data.tmp);
			}
		}
		i++;
	}
	waitpid(pid, &status, 0);//XXX note: étant donné que le parent continue son exe, il faudrai pas mettre le wait dans la boucle pour éviter qu'ils n'execute tout les enfant ?
	g_data.last_exit_code = WEXITSTATUS(status);
	print_debug_sep("END");
}

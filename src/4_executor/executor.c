/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:07:10 by awillems          #+#    #+#             */
/*   Updated: 2022/07/04 15:27:41 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int		is_build_in(char *cmd);
int		exe_build_in(char **args, int index, int fds[2]);
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

void	close_all_next_fds(size_t i)
{
	while (++i < get_instr_list()->len)
	{
		if (get_instr(i)->type != 1)
			continue ;
		close_fd_pipe(get_instr(i)->fds);
	}
}

void	execute_cmd(size_t i, char *cmd, char **args, char **envp)
{
	close_all_next_fds(i);
	if (get_instr(i)->err != 0)
		msh_exit(get_instr(i)->err, strerror(errno), __FUNCTION__);
	set_fd_to_std(get_instr(i)->fds, STDIN_FILENO, STDOUT_FILENO);
	if (cmd && (cmd[0] == '/' || cmd[0] == '.'))
		exe_file(cmd, args, envp);
	else
	{
		exe_normal(cmd, args, envp);
		msh_exit(EX_NOTFOUND, "command not found", __FUNCTION__);
	}
	msh_exit(0, NULL, __FUNCTION__);
}

void	line_executor(pid_t pid, int status, size_t i, int index)
{
	print_debug_sep("EXECUTION");
	while (++i < get_instr_list()->len)
	{
		if (get_instr(i)->type != 1)
			continue ;
		index = is_build_in(get_instr_arg_elem(i, 0));
		if (index != -1)
			exe_build_in(get_instr_arg(i)->buffer, index, get_instr(i)->fds);
		else
		{
			pid = 0;
			pid = fork();
			if (pid == 0)
				execute_cmd(i, get_instr_arg_elem(i, 0),
					get_instr_arg(i)->buffer, g_data.env.buffer);
			close_fd_pipe(get_instr(i)->fds);
			waitpid(pid, &status, WNOHANG);
		}
	}
	if (index == -1)
	{
		waitpid(pid, &status, 0);
		g_data.last_exit_code = WEXITSTATUS(status);
	}
	print_debug_sep("END");
}

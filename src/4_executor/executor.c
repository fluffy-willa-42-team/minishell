/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:07:10 by awillems          #+#    #+#             */
/*   Updated: 2022/06/24 12:40:09 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int		exe_build_in(char *cmd, char **args, char **envp);
void	exe_normal(char *cmd, char **args, char **envp);

void	print_cmd(size_t i)
{
	size_t j = 0;
	printf("%d => [%s", get_instr(i)->fds[0], get_instr_arg_elem(i, j));
	j++;
	while (j < get_instr_arg(i)->content_len)
		printf(", %s", get_instr_arg_elem(i, j++));
	printf("] => %d\n", get_instr(i)->fds[1]);
}

void	execute_cmd(size_t i)
{
	pid_t	pid;
	int		status;
	char	**envp = NULL;
	char	**args = get_instr_arg(i)->buffer;
	char	*cmd = get_instr_arg_elem(i, 0);
	
	pid = fork();
	if (pid == 0)
	{
		print_cmd(i);
		if (get_instr(i)->err != 0)
		{
			printf("Error: %s\n", strerror(get_instr(i)->err));
			exit(get_instr(i)->err);
		}
		if (cmd[0] == '/' || cmd[0] == '.')
			execve(cmd, args, envp);
		else if (exe_build_in(cmd, args, envp))
			exit(0);
		else
			exe_normal(cmd, args, envp);
		printf("error: command not found\n");
		exit(EKEYEXPIRED);
	}
	waitpid(pid, &status, 0);
	vec_delete(&g_data.tmp);
	g_data.last_exit_code = WEXITSTATUS(status);
}

void	line_executor(void)
{
	printf("\e[0;36m0=====-----	EXECUTION	-----=====0\n\e[0m");
	for (size_t i = 0; i < get_instr_list()->content_len; i++)
	{
		if (get_instr(i)->type == 1)
			execute_cmd(i);
	}
	printf("\e[0;36m0=====-----	END		-----=====0\n\e[0m");
}

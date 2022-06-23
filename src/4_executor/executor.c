/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:07:10 by awillems          #+#    #+#             */
/*   Updated: 2022/06/23 13:03:23 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <string.h>
// #include <sys/types.h>
#include <sys/wait.h>

void	exit_minishell(int code, char *message);

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
	// const t_instr *instr = get_instr(i);
	
	pid = fork();
	if (pid == 0)
	{
		print_cmd(i);
		if (get_instr(i)->err != 0)
		{
			printf("Error: %s\n", strerror(get_instr(i)->err));
			exit(get_instr(i)->err);
		}
		exit(0);
	}
	waitpid(pid, &status, 0);
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

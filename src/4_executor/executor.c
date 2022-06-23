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

void	exit_minishell(int code, char *message);

void	print_cmd(size_t i)
{
	size_t j = 0;
	printf("%d => [%s", get_instr(i)->fds[0], get_instr_arg_elem(i, j));
	j++;
	while (j < get_instr_arg(i)->content_len)
		printf(", %s", get_instr_arg_elem(i, j++));
	printf("] => %d\n", get_instr(i)->fds[1]);
	// if (is_build_in(i))
		// printf("BUILD IN\n");		
}

int	execute_cmd(size_t i)
{
	// const t_instr *instr = get_instr(i);
	
	print_cmd(i);
	return (1);
}

void	line_executor(void)
{
	printf("\e[0;36m0=====-----	EXECUTION	-----=====0\n\e[0m");
	for (size_t i = 0; i < get_instr_list()->content_len; i++)
	{
		if (get_instr(i)->type == 1)
			if (!execute_cmd(i))
				break ;
	}
	printf("\e[0;36m0=====-----	END		-----=====0\n\e[0m");
}

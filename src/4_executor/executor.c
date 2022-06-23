/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:07:10 by awillems          #+#    #+#             */
/*   Updated: 2022/06/23 10:59:46 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

void	exit_minishell(int code, char *message);

void	print_cmd(size_t i)
{
	size_t j = 0;
	printf("%d => [%s", get_instr(i)->file_descriptor[0], get_instr_arg_elem(i, j));
	j++;
	while (j < get_instr_arg(i)->content_len)
		printf(", %s", get_instr_arg_elem(i, j++));
	printf("] => %d\n", get_instr(i)->file_descriptor[1]);
}

void	execute_cmd(size_t i)
{
	const t_instr *instr = get_instr(i);
	
	print_cmd(i);
	if (instr->file_descriptor[0] == -1 || instr->file_descriptor[1] == -1)
		exit_minishell(1, "No such file or directory");
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

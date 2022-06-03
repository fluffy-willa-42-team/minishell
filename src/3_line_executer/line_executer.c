/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_executer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:52:02 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 15:38:24 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

#include <stdio.h>

void	msh_cmd(t_instr *instr)
{
	printf("NEW CMD\n");
	size_t i = 0;
	while (vec_get_str_array_raw(&instr->arg, i))
	{
		printf("    [%lu] %s\n", i, vec_get_str_array_raw(&instr->arg, i));
		i++;
	}
}

void	msh_pipe(void)
{
	printf(" |\n V\n");
}

void	exec_cmd(t_vec *instr_list, int index)
{
	static char	*spec_str[] = {"|", ";", ">>", ">", "<<", "<"};
	static void	(*func_link[6])() = {
		msh_pipe, msh_pipe, msh_pipe, msh_pipe, msh_pipe, msh_pipe
	};

	t_instr	*instr =  vec_get_instr_raw(instr_list, index);
	if (instr->type == 0)
		return ;
	else if (instr->type == 1)
		msh_cmd(instr);
	else if (instr->type == 2)
	{
		char		*ptr = vec_get_str_array_raw(&instr->arg, 0);
		int			i = 0;

		while (i < 6)
		{
			if (ft_strcmp(ptr, spec_str[i]) == 0)
				func_link[i]();
			i++;
		}
	}
	return (exec_cmd(instr_list, index + 1));
}

void	line_executer(t_vec *instr_list)
{
	exec_cmd(instr_list, 0);
}

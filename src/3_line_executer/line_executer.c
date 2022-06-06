/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_executer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:52:02 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 12:12:41 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

#include <stdio.h>

void	msh_cmd(t_instr *instr, int index)
{
	printf("NEW CMD\n");
	size_t i = 0;
	(void) instr;
	while (i < get_instr_arg(index)->content_len)
	{
		printf("    [%lu] %s\n", i, get_instr_arg_elem(index, i));
		i++;
	}
}

void	msh_pipe(void)
{
	printf(" |\n V\n");
}

void	msh_semicolumn(void)
{
	printf("----------\n");
}

void	msh_redir_front(void)
{
	printf(" V\n V\n");
}

void	msh_redir_back(void)
{
	printf(" ^\n ^\n");
}

void	exec_cmd(t_vec *instr_list, int index)
{
	static char	*spec_str[] = {"|", ";", ">>", ">", "<<", "<"};
	static void	(*func_link[6])() = {
		msh_pipe, msh_semicolumn,
		msh_redir_front, msh_redir_front,
		msh_redir_back, msh_redir_back
	};

	t_instr	*instr =  get_raw_instr(index);
	if (!instr || instr->type == 0)
		return ;
	else if (instr->type == 1)
		msh_cmd(instr, index);
	else if (instr->type == 2)
	{
		char		*ptr = get_instr_arg_elem(index, 0);
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

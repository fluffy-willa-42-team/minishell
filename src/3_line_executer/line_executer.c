/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_executer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:52:02 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 13:41:04 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

#include <stdio.h>

void	line_executer(t_vec *instr_list)
{
	t_instr	*instr;
	size_t i = 0;

	instr = vec_get_instr(instr_list, 0);
	while (i < instr_list->content_len)
	{
		if (instr->type == 0){
			size_t y = 0;
			while (y < instr->arg.content_len)
			{
				printf("%lu CMD => %s\n", y, vec_get_str_array_raw(&instr->arg, y));
				y++;
			}
		}
		i++;
		instr = vec_get_instr(instr_list, i);
	}
	return ;
}
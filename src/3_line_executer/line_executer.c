/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_executer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:52:02 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 13:48:06 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

#include <stdio.h>

void	line_executer(t_vec *instr_list)
{
	t_instr	*instr;
	size_t i = 0;

	while (i < instr_list->content_len)
	{
		instr = vec_get_instr(instr_list, i);
		if (instr->type == 1){
			printf("CMD [0] => %s\n", vec_get_str_array_raw(&instr->arg, 0));
			size_t y = 1;
			while (y < instr->arg.content_len)
			{
				printf("ARG [%lu] => %s\n", y, vec_get_str_array_raw(&instr->arg, y));
				y++;
			}
		}
		i++;
	}
	return ;
}
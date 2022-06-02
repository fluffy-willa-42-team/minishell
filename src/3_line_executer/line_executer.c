/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_executer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:52:02 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 13:19:08 by awillems         ###   ########.fr       */
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
		printf("%lu %d\n", i, instr->type);
		i++;
		instr = vec_get_instr(instr_list, i);
	}
	return ;
}
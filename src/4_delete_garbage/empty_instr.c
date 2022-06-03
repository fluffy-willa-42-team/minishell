/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:20:06 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 12:32:51 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

void	empty_instr(t_vec *instr)
{
	size_t i = 0;

	while (i < instr->content_len)
	{
		vec_get_instr(instr, i)->type = 0;
		vec_delete(&(vec_get_instr(instr, i)->arg));
		i++;
	}
}
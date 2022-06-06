/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:20:06 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 11:41:05 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

void	empty_g_data(void)
{
	size_t i = 0;

	vec_delete(get_line());
	while (i < g_data.lexed_instr.content_len)
	{
		get_instr(i)->type = 0;
		vec_delete(get_instr_arg(i));
		i++;
	}
}
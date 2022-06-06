/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:20:06 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 14:40:53 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

void	empty_g_data(void)
{
	size_t i = 0;

	vec_delete(&g_data.lexed_command);
	while (i < g_data.lexed_instr.content_len)
	{
		vec_get_instr(&g_data.lexed_instr, i)->type = 0;
		vec_delete(&(vec_get_instr(&g_data.lexed_instr, i)->arg));
		i++;
	}
}
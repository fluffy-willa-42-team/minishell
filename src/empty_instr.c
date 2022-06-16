/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:20:06 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 08:56:20 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

int	change_str_to_int(char **input, int *output)
{
	(void) input;
	*output = 0;
	return (1);
}

void	empty_g_data(void)
{
	size_t i = 0;

	vec_delete(get_line());
	while (i < g_data.lexed_instr.content_len)
	{
		vec_cast(get_instr_arg(i), sizeof(int), change_str_to_int);
		vec_delete(get_instr_arg(i));
		get_instr(i)->type = 0;
		i++;
	}
}

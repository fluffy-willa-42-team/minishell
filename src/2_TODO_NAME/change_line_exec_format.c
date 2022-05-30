/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_line_exec_format.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 10:50:44 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

#include "debug.h"

void	change_line_to_exec_format(t_vec *line, t_vec *instr)
{
	int i = 0;

	// g_data.env_path = ft_split(, ':');
	
	(void) instr;
	while (i < line->len)
	{
		if (vec_get_char(line, i) != 0 && ( i == 0 || vec_get_char(line, i - 1) == 0))
		{
			// is_binary = is_bin();
			printf("=> [%s]\n", &line->buffer[i]);
		}
		i++;
	}
}
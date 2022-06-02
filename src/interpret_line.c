/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:59:33 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 11:44:28 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include "vec_utils.h" /* vec_get_instr */

void	line_cleaner(t_vec *vec, char *line);
void	line_lexer(t_vec *Line, t_vec *instr);

/**
 * @brief After the execution will free the struc with the instruction
 * //TODO
 */
static void	destroy_line_alloc(t_vec *instr)
{
	int	i;

	i = 0;
	while (i < instr->content_len)
	{
		vec_delete(vec_get_instr(instr, i)->arg);
		i++;
	}
}


int	interpret_line(char *line)
{
	line_cleaner(&g_data.lexed_command, line);
	line_lexer(&g_data.lexed_command, &g_data.lexed_instr);
	//execute
	destroy_line_alloc(&g_data.lexed_instr);
	vec_delete(&g_data.lexed_command);
	return (1);
}

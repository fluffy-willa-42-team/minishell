/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:59:33 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 10:18:00 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	line_cleaner(t_vec *vec, char *line);
void	line_lexer(t_vec *Line, t_vec *instr);

/**
 * @brief After the execution will free the struc with the instruction
 * //TODO
 */
static void	destroy_line_alloc(void)
{

}


int	interpret_line(char *line)
{
	line_cleaner(&g_data.lexed_command, line);
	line_lexer(&g_data.lexed_command, &g_data.lexed_instr);
	//execute
	destroy_line_alloc();
	vec_delete(&g_data.lexed_command);
	return (1);
}

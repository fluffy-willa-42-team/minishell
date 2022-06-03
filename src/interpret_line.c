/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:59:33 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 11:56:57 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include "vec_utils.h" /* vec_get_instr */

void	line_cleaner(t_vec *vec, char *line);
void	line_lexer(t_vec *Line, t_vec *instr);

void	line_lexer(t_vec *line, t_vec *instr);
void	line_executer(t_vec *instr);

int	interpret_line(char *line)
{
	line_cleaner(&g_data.lexed_command, line);
	line_lexer(&g_data.lexed_command, &g_data.lexed_instr);
	//execute
	// line_executer(&g_data.lexed_instr);

	vec_delete(&g_data.lexed_command);
	// vec_delete(&g_data.lexed_instr);
	return (1);
}

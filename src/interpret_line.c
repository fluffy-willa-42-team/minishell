/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:59:33 by awillems          #+#    #+#             */
/*   Updated: 2022/05/31 12:08:07 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	line_lexer(t_vec *vec, char *line);
void	change_line_to_exec_format(t_vec *Line, t_vec *instr);

int	interpret_line(char *line)
{
	printf("\"%s\"\n", line);
	line_lexer(&g_data.lexed_command, line);
	change_line_to_exec_format(&g_data.lexed_command, &g_data.lexed_instr);
	vec_delete(&g_data.lexed_command);
	return (1);
}

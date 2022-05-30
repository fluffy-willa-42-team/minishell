/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:59:33 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 10:10:55 by awillems         ###   ########.fr       */
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
	vec_delete_content(&g_data.lexed_command);
	return (1);
}

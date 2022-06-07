/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:59:33 by awillems          #+#    #+#             */
/*   Updated: 2022/06/07 13:20:57 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include "vec_utils.h" /* vec_get_instr */

void	line_cleaner(t_vec *vec, char *line);
int		line_lexer(void);
void	line_executer(t_vec *instr);
void	empty_g_data(void);
void	print_instr(size_t len);

int	interpret_line(char *line)
{
	printf("=> [%s]\n", line);

	line_cleaner(&g_data.lexed_command, line);
	vec_print(&g_data.lexed_command);

	int nb_cmd = line_lexer();
	
	(void) nb_cmd;
	vec_print(&g_data.lexed_command);
	print_instr(nb_cmd);

	// line_executer(&g_data.lexed_instr);
	empty_g_data();
	return (1);
}

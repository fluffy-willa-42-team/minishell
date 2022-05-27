/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:09:06 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 12:09:09 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

#include <stdio.h>

void	interpret_spec_char(t_vec *res, const char *line);
void	clean_whitespace(t_vec *res);

void	line_lexer(char *line)
{
	// Interpret special char
	interpret_spec_char(&g_data.lexed_command, line);
	// Remove whitespaces
	clean_whitespace(&g_data.lexed_command);
	// expand vars
	vec_print(&g_data.lexed_command);
	return ;
}

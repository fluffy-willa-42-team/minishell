/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:13 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/26 15:11:22 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_debug.h"

#include "vector_lib.h"
#include "libft.h"

#include "msh_struct.h"

#include <readline/history.h>
#include <stdlib.h>

void	san_whitespace(t_vec *res, const char *line);/** @file msh_sanitizer.c*/
void	expend_var(t_vec *line);					/** @file msh_expend_var.c*/
// void	escape_character(t_vec *res, const char *line);/** @file msh_escape.c */

void	msh_lexer(const char *line)
{
	// transform char /special char in double quotes


												//CLOSE	OPEN BRACKET OR QUOTES
												
	// escape_character(&g_data.str_list, line);							//TRANSFORMS UNWRITABLE CHAR
	san_whitespace(&g_data.str_list, line);		//REMOVE WHITESPACES
	expend_var(&g_data.str_list);				//REPLACE VARIABLE
	printf("lexer(\"%s\")\n", g_data.str_list.buffer);
	// return (line || strcat(line, input_buffer));
}

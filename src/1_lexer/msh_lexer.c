/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:13 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/26 12:45:03 by awillems         ###   ########.fr       */
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

void	msh_lexer(const char *line)
{
	
	
	// transform char /special char in double quotes


												//CLOSE	OPEN BRACKET OR QUOTES
												
	// add_history("TODO");
	// escape_character							//TRANSFORMS UNWRITABLE CHAR
	san_whitespace(&g_data.str_list, line);		//REMOVE WHITESPACES
	expend_var(&g_data.str_list);				//REPLACE VARIABLE
	printf("lexer(\"%s\")\n", g_data.str_list.buffer);
}

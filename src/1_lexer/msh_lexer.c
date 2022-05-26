/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:13 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/26 11:20:00 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_debug.h"

#include "vector_lib.h"
#include "libft.h"

#include "msh_struct.h"

// getenv
#include <stdlib.h>

/** @file msh_sanitizer.c */
void	sanitize_whitespaces(t_vec *res, const char *line);

/** @file msh_expend_var.c */
void	expend_var(t_vec *line);

void	msh_lexer(const char *line)
{
	g_data.str_list = vec_init(sizeof(char));
	sanitize_whitespaces(&g_data.str_list, line);
	expend_var(&g_data.str_list);
	printf("lexer(\"%s\")\n", g_data.str_list.buffer);//TODO REMOVE
}

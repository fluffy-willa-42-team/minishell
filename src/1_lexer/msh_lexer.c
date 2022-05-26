/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:13 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/26 10:10:43 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_debug.h"

#include "vector_lib.h"

/** @file msh_sanitizer.c */
void	sanitize_whitespaces(t_vec *res, const char *line);

void	msh_lexer(const char *line)
{
	t_vec res = vec_init(sizeof(char));
	
	sanitize_whitespaces(&res, line);
	printf("lexer(\"%s\")\n", res.buffer);//TODO REMOVE
	vec_delete(&res);
}

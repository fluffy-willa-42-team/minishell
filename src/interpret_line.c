/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:59:33 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 12:51:04 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	line_lexer(t_vec *vec, char *line);

int	interpret_line(char *line)
{
	printf("\"%s\"\n", line);
	line_lexer(&g_data.lexed_command, line);
	vec_delete_content(&g_data.lexed_command);
	return (1);
}

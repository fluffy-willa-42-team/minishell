/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:09:06 by awillems          #+#    #+#             */
/*   Updated: 2022/06/07 13:33:49 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include "line_cleaner.h"

#include <stdio.h>

void	interpret_spec_char(t_vec *res, const char *line);
void	clean_whitespace(t_vec *res);

/**
 *  Index   Conv   Function
 *  ------|------|---------
 *   [0]  | ` `  | whtspc
 *   [1]  | `\t` | whtspc
 *   [2]  | `\n` | whtspc
 *   [3]  | `\v` | whtspc
 *   [4]  | `\f` | whtspc
 *   [5]  | `\r` | whtspc
 *   [6]  | `$`  | varsub
 *   [7]  | `\'` | sglqot
 *   [8]  | `\"` | dblqot
 *   [9]  | `<`  | redir
 *   [A]  | `>`  | redir
 *   [B]  | `|`  | redir
 *   [C]  | `\\` | bkslh
 *
 */

void	line_cleaner(t_vec *vec, char *line)
{
	static int	(*func_link[7])() = {
		varsub, sglqot, dblqot, redir, redir, redir, bkslh
	};
	static char	*to_find = "$\'\"<>|\\";
	int			i;
	char		*ptr;

	i = 0;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	while (line[i])
	{
		ptr = ft_strchr(to_find, line[i]);
		if (ptr)
		{
			printf("[_%c_]\n", *ptr);
			i = func_link[ptr - to_find](vec, line, i);
		}
		else
		{
			printf("[-%c-]\n", line[i]);
			printf("Word\n");
			while (line[i] &&
					!ft_strchr(to_find, line[i]) &&
					!ft_is_whitespace(line[i]))
			{
				vec_add(vec, &line[i]);
				i++;
			}
			if (line[i] && ft_is_whitespace(line[i]))
			{
				vec_add(vec, "\0");
				i++;
			}
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:09:06 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 12:06:52 by mahadad          ###   ########.fr       */
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
 *   [7]  | `\\` | bkslh
 *   [7]  | `<`  | redir
 *   [7]  | `>`  | redir
 *   [7]  | `|`  | redir
 *
 */

void	line_cleaner(t_vec *vec, char *line)
{
	static int	(*func_link[13])() = {
		whtspc, whtspc, whtspc, whtspc, whtspc, whtspc,
		varsub, sglqot, dblqot, redir, redir, redir, bkslh
	};
	static char	*to_find = " \t\n\v\f\r$\'\"<>|\\";
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
			printf("[%c]\n", *ptr);
			i = func_link[ptr - to_find](vec, line, i);
		}
		else
		{
			printf("Word\n");
			while (line[i] && !ft_strchr(to_find, line[i]))
			{
				p_vec_add(vec, &line[i]);
				i++;
			}
			p_vec_add(vec, "\0");
		}
	}
	vec_print(vec);
	return ;
}

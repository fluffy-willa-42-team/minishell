/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:09:06 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 15:22:58 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include "lexer.h"

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
 *
 */

void	line_lexer(t_vec *vec, char *line)
{
	static int	(*func_link[10])() = {
		whtspc, whtspc, whtspc, whtspc, whtspc, whtspc, 
		varsub, bkslh, sglqot, dblqot
	};
	static char *to_find = " \t\n\v\f\r$\\\'";
	int i;
	void	*ptr;

	i = 0;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	while (line[i])
	{
		ptr = ft_strrchr(to_find, line[i]);
		if (ptr)
			i = func_link[ft_strrchr(to_find, line[i]) - to_find](vec, line, i);
		else
		{
			vec_fill(vec, FIXED_LEN, &line[i], 1);
			i++;
		}
	}
	vec_print(vec);
	return ;
}

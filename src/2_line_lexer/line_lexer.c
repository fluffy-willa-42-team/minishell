/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 09:40:42 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <stdlib.h>    /** getenv */

#include "line_lexer.h"
#include "debug.h"

void	print_instr(void);

/**
 * @brief //TODO WIP
 * 
 * @param line 
 * @return char* 
 */
char *find_bin_path(char *line)
{
	(void)line;
	return ("WIP/bin/");
}

void	set_bin_path(t_vec *line, int index)
{
	// Check if the CMD is a bin with path
	if (access(vec_get_str(line, index), X_OK) != -1)
	{
		return ;
	}
	// find the good path
	vec_insert(line, DEFAULT, index, find_bin_path(vec_get_str(line, index)));
}

// static void	vec_add_instr(t_vec *instr, int instr_index, int type)
// {
// 	t_instr new;
// 	(void) instr;
// 	(void) new;
// 	(void) instr_index;
// 	(void) type;
// }

/**
 *  Index   Conv   Function
 *  ------|------|---------
 *   [0]  | ` `  | inredir
 *   [1]  | `<`  | inredir
 *   [2]  | `>`  | outredir
 *   [3]  | `|`  | ppe      // note: `pipe` is a reserved key word <unistd.h>
 * 
 * func_link[index](int line_index, t_vec *line, t_vec *instr)
 */

void	line_lexer(t_vec *line, t_vec *instr)
{
	size_t		i;
	// static int	(*func_link[])() = {inredir, outredir, ppe};
	// static char	*to_find = " <>|";
(void)instr;
	i = 0;
	while (i < line->content_len)
	{
		if (vec_get_char(line, i) && (i == 0 || !vec_get_char(line, i - 1)))
			printf("[%lu]: %s\n", i, vec_get_str(line, i));
		i++;
	}
	
	print_instr();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 11:18:58 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <stdlib.h>    /** getenv */

#include "debug.h"

void	print_instr(void);
int		is_special_elem(char *elem);
void	set_bin_path(t_vec *line, int index);

void	line_lexer(t_vec *line, t_vec *instr)
{
	(void) instr;
	int	is_cmd = 1;
	int	cmd_index = 0;
	for (size_t i = 0; i < line->content_len; i++)
	{
		// if (line[i] != 0 && (i == 0 || line[i-1] == 0))
		if (vec_get_char(line, i) != 0 && (i == 0 || vec_get_char(line, i - 1) == 0))
		{
			// if (is_special_elem(&line[i]) != 0)
			if (is_special_elem(vec_get_str(line, i)) != 0)
			{
				printf("[%d]     %s\n", cmd_index, vec_get_str(line, i));
				is_cmd = 1;
				cmd_index++;
				// CREATE / REUSE REDIRECT INSTR
			}
			else if (is_cmd)
			{
				printf("[CMD %d] %s\n", cmd_index, vec_get_str(line, i));
				is_cmd = 0;
				cmd_index++;
				// CREATE / REUSE CMD
			}
			else
			{
				printf("  [ARG] %s\n", vec_get_str(line, i));
				// UPDATE LAST CMD
			}
		}
	}
}

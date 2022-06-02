/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 13:17:15 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <stdlib.h>    /** getenv */

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
		return ;
	// find the good path
	vec_insert(line, DEFAULT, index, find_bin_path(vec_get_str(line, index)));
}

void	line_lexer(t_vec *line, t_vec *instr)
{
	size_t i = 0;
	int	first_elem = 1;
	int	coun_elem = -1;

	g_data.env_path = getenv("PATH");
	vec_delete(instr);
	while (i < line->content_len)
	{
		if (vec_get_char(line, i) != 0 && ( i == 0 || vec_get_char(line, i - 1) == 0))
		{
			if (ft_strchr("<>|", vec_get_char(line, i)))
			{
				coun_elem++;
				printf("PIPE ");
				vec_add_instr(instr, 2);
				vec_add_char_ptr(get_instr_arg(coun_elem), vec_get_str(line, i));
				first_elem = 1;
			}
			else
			{
				if (first_elem)
				{
					coun_elem++;
					// Add the path to the bin in the line buffer.
					set_bin_path(line, i);
					// Create new instrcution struct in the buffer.
					vec_add_instr(instr, 0);
					vec_add_char_ptr(get_instr_arg(coun_elem), vec_get_str(line, i));
					printf("CMD ");
					first_elem = 0;
				}
				else
				{
					vec_add_char_ptr(get_instr_arg(coun_elem), vec_get_str(line, i));
					printf("ARG ");
				}
			}
			printf("[%d]=> [%s]\n", coun_elem, vec_get_str(line, i));
		}
		i++;
	}
	print_instr();
}

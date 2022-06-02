/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 15:49:14 by mahadad          ###   ########.fr       */
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
	{
		return ;
	}
	// find the good path
	vec_insert(line, DEFAULT, index, find_bin_path(vec_get_str(line, index)));
}

static void	vec_add_instr(t_vec *instr, int instr_index, int type)
{
	t_instr new;

	// if (vec_is_empty(instr, instr_index) || vec_is_empty(get_instr_arg(instr_index), instr_index))
	if (vec_is_empty(instr, instr_index) || !get_instr_arg(instr_index)->len)
	{
		new.arg = vec_init(sizeof(char *));
		new.arg.rate = 8;
		new.type = type;
		p_vec_add(instr, &new);
		printf("### new instr ! ###\n");
		return ;
	}
	vec_get_instr(instr, instr_index)->type = type;
}

void	line_lexer(t_vec *line, t_vec *instr)
{
	size_t i = 0;
	int	first_elem = 1;
	int	coun_elem = -1;

	g_data.env_path = getenv("PATH");
	while (i < line->content_len)
	{
		if (vec_get_char(line, i) != 0 && ( i == 0 || vec_get_char(line, i - 1) == 0))
		{
			if (ft_strchr("<>|", vec_get_char(line, i)))
			{
				printf("[##### PIPE #####]\n");
				coun_elem++;
				vec_add_instr(instr, coun_elem, 2);
				vec_add_char_ptr(get_instr_arg(coun_elem), vec_get_str(line, i));
				first_elem = 1;
			}
			else
			{
				if (first_elem)
				{
						printf("[##### CMD #####]\n");
					coun_elem++;
					// Add the path to the bin in the line buffer.
					set_bin_path(line, i);
					// Create new instrcution struct in the buffer.
					vec_add_instr(instr, coun_elem, 0);//TODO WIP
					vec_add_char_ptr(get_instr_arg(coun_elem), vec_get_str(line, i));
					first_elem = 0;
				}
				else
				{
					printf("[##### ARG #####]\n");
					vec_add_char_ptr(get_instr_arg(coun_elem), vec_get_str(line, i));
				}
			}
			printf("[%d]=> [%s]\n", coun_elem, vec_get_str(line, i));
		}
		i++;
	}
			print_instr();
}

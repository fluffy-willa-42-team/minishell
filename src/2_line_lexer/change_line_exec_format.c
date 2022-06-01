/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_line_exec_format.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/06/01 14:41:21 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include "msh_bin_handler.h"
#include <stdlib.h>    /** getenv */

#include "debug.h"

void	create_new_instr(int type, t_vec *instr)
{
	t_instr	new;

	new.arg = vec_init(sizeof(char *));
	new.arg.rate = 8;
	new.type = type;
	vec_add_instr(instr, new);
}

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
	vec_print(line);
}

/**
 *           Rework all the function
 *           [ ] avoid vec_get_stuff(&(vec_get(&(vec_get)->stuff)))
 *           [ ] when CMD find the path to the bin
 */

/**
 * @brief Get the arg vector.
 * 
 * @param index The index of element.
 * @return t_vec* Return a ptr to the vector.
 */
t_vec	*get_instr_arg(int index)
{
	return (&(vec_get_instr(&g_data.lexed_instr, index)->arg));
}

static void	instr_debug(void)
{
	printf("[\n");
	for (size_t x = 0; x < g_data.lexed_instr.content_len; x++)
	{
		printf("    {\n");
		printf("        type: %d,\n", vec_get_instr(&g_data.lexed_instr, x)->type);
		size_t owo = 0;
		size_t uwu = get_instr_arg(x)->content_len;
		printf("        content_len: %lu,\n", uwu);
		printf("        arg: [\n");
		while (uwu)
		{
			printf("            [%lu]: \"%s\",\n",
					owo, vec_get_str2(get_instr_arg(x), owo));
			uwu--;
			owo++;
		}
		printf("        ],\n");
		printf("    },\n");
	}
	printf("]\n");
}

void	change_line_to_exec_format(t_vec *line, t_vec *instr)
{
	size_t i = 0;
	int	first_elem = 1;
	int	coun_elem = -1;

	g_data.env_path = getenv("PATH");
	if (MSH_DEBUG) printf("[INFO] env updated, PATH:%s\n", g_data.env_path);
	vec_delete(instr);
	while (i < line->content_len)
	{
		if (vec_get_char(line, i) != 0 && ( i == 0 || vec_get_char(line, i - 1) == 0))
		{
			if (ft_strchr("<>|", vec_get_char(line, i)))
			{
				coun_elem++;
				printf("PIPE ");
				create_new_instr(2, instr);
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
					vec_print(line);
					// Create new instrcution struct in the buffer.
					create_new_instr(0, instr);
					printf("[%d][[[%s]]]\n",coun_elem , vec_get_str(line, i));
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
			instr_debug();
		}
		i++;
	}
}

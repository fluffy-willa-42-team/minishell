/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_line_exec_format.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/05/31 17:26:23 by mahadad          ###   ########.fr       */
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

	new.arg = vec_init(sizeof(t_instr));
	new.type = type;
	vec_add(instr, &new);
}

void	set_bin_path(t_vec *arg, char *line)
{
	if (is_bin(line))
	{
		vec_add(arg, line);
		return ;
	}
	// make else
}

void	reset_instr(void)
{
	vec_delete(&g_data.lexed_instr);
}

/**
 * //TODO
 * //TODO
 *           Rework all the function
 *           [ ] avoid vec_get_stuff(&(vec_get(&(vec_get)->stuff)))
 * //TODO
 * //TODO
 */

void	change_line_to_exec_format(t_vec *line, t_vec *instr)
{
	size_t i = 0;
	int	first_elem = 1;
	int	coun_elem = -1;

	g_data.env_path = getenv("PATH");
	if (MSH_DEBUG)
		printf("[INFO] env updated, PATH:%s\n", g_data.env_path);
	
	reset_instr();

	while (i < line->content_len)
	{
		if (vec_get_char(line, i) != 0 && ( i == 0 || vec_get_char(line, i - 1) == 0))
		{
			if (ft_strchr("<>|", vec_get_char(line, i)))
			{
				coun_elem++;
				printf("PIPE ");
				create_new_instr(2, instr);
				vec_add(&(vec_get_instr(&g_data.lexed_instr, coun_elem)->arg), &line->buffer[i]);
				first_elem = 1;
			}
			else
			{
				if (first_elem)
				{
					coun_elem++;
					create_new_instr(0, instr);
					set_bin_path(&(vec_get_instr(&g_data.lexed_instr, coun_elem)->arg), &line->buffer[i]);
					printf("CMD ");
					first_elem = 0;
				}
				else
				{
					vec_add(&(vec_get_instr(&g_data.lexed_instr, coun_elem)->arg), &line->buffer[i]);
					printf("ARG ");
				}
			}
			printf("[%d]=> [%s]\n", coun_elem, &line->buffer[i]);
		}
		i++;
	}
	for (size_t x = 0; x < g_data.lexed_instr.content_len; x++)
	{
		printf("[\n");
		printf("    type: %d,\n", vec_get_instr(&g_data.lexed_instr, x)->type);
		size_t owo = 0;
		size_t uwu = vec_get_instr(&g_data.lexed_instr, x)->arg.content_len;
		printf("    content_len: %lu,\n", uwu);

		printf("    arg: {\n");
		while (uwu)
		{
			printf("        [%lu]: \"%s\"\n",
					owo, vec_get_str(&(vec_get_instr(&g_data.lexed_instr, x)->arg), owo));
			uwu--;
			owo++;
		}
		printf("    },\n");
		printf("],\n");
	}
	
}
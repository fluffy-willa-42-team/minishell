/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 13:11:39 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <stdlib.h>    /** getenv */

#include "line_lexer.h"
#include "debug.h"

void	print_instr(size_t len);
int		is_special_elem(char *elem);
void	set_bin_path(t_vec *line, int index);

void	add_arg(t_vec* instr, size_t index, char *arg)
{
	printf("  [ARG] %s %lu\n", arg, index);
	// UPDATE LAST CMD
	vec_add_char_ptr(&vec_get_instr(instr, index)->arg, arg);
}

void	new_instr(t_vec* instr, size_t index, int type, char *arg)
{
	t_instr new_instr;
	
	// CREATE / REUSE INSTR
	printf("[INSTR %lu]\n", index);
	if (index >= instr->content_len)
	{
		new_instr.type = type;
		new_instr.arg = vec_init(sizeof(char *));
		new_instr.arg.rate = 8;
		vec_add(instr, &new_instr);
		add_arg(instr, index, arg);
	}
	else if (vec_get_instr(instr, index)->type == 0)
	{
		vec_get_instr(instr, index)->type = type;
		add_arg(instr, index, arg);
	}
}

void	line_lexer(t_vec *line, t_vec *instr)
{
	int	is_cmd = 1;
	int	cmd_index = -1;
	for (size_t i = 0; i < line->content_len; i++)
	{
		// if (!(line[i] != 0 && (i == 0 || line[i-1] == 0)))
		if (!(vec_get_char(line, i) != 0 && (i == 0 || vec_get_char(line, i - 1) == 0)))
			continue;
		if (is_special_elem(vec_get_str(line, i)) != 0)
		{
			cmd_index++;
			is_cmd = 1;
			new_instr(instr, cmd_index, 2, vec_get_str(line, i));
		}
		else if (is_cmd)
		{
			cmd_index++;
			is_cmd = 0;
			new_instr(instr, cmd_index, 1, vec_get_str(line, i));
		}
		else
			add_arg(instr, cmd_index, vec_get_str(line, i));
	}
	printf("\n\n");
	print_instr(cmd_index + 1);
}

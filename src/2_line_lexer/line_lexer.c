/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 12:47:32 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <stdlib.h>    /** getenv */

#include "debug.h"

void	print_instr(size_t len);
int		is_special_elem(char *elem);
void	set_bin_path(t_vec *line, int index);

void	add_arg(t_vec* instr, int index, char *arg)
{
	printf("  [ARG] %s\n", arg);
	// UPDATE LAST CMD
	(void) instr;
	(void) index;
	(void) arg;
	// vec_add_char_ptr(vec_get_instr(instr, index), arg);
}

void	new_instr(t_vec* instr, size_t index, int type, char *arg)
{
	t_instr new_instr;
	
	// CREATE / REUSE INSTR
	printf("[INSTR]\n");
	if (index >= instr->content_len)
	{
		printf("new INSTR\n");
		new_instr.type = type;
		new_instr.arg = vec_init(sizeof(char *));
		new_instr.arg.rate = 8;
		vec_add(instr, &new_instr);
		add_arg(instr, index, arg);
	}
	else if (vec_get_instr(instr, index)->type == 0)
	{
		printf("old INSTR\n");
		new_instr.type = type;
		add_arg(instr, index, arg);
	}
	else
		printf("existing INSTR\n");
}

void	line_lexer(t_vec *line, t_vec *instr)
{
	int	is_cmd = 1;
	int	cmd_index = 0;
	for (size_t i = 0; i < line->content_len; i++)
	{
		// if (!(line[i] != 0 && (i == 0 || line[i-1] == 0)))
		if (!(vec_get_char(line, i) != 0 && (i == 0 || vec_get_char(line, i - 1) == 0)))
			continue;
		if (is_special_elem(vec_get_str(line, i)) != 0)
		{
			is_cmd = 1;
			new_instr(instr, cmd_index, 2, vec_get_str(line, i));
			cmd_index++;
		}
		else if (is_cmd)
		{
			is_cmd = 0;
			new_instr(instr, cmd_index, 1, vec_get_str(line, i));
			cmd_index++;
		}
		else
			add_arg(instr, cmd_index, vec_get_str(line, i));
	}
	print_instr(cmd_index);
}

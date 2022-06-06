/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 14:52:11 by awillems         ###   ########.fr       */
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

static void	add_arg(t_vec* instr, size_t index, char *arg)
{
	vec_add_char_ptr(&vec_get_instr(instr, index)->arg, arg);
}

static void	new_instr(t_vec* instr, size_t index, int type, char *arg)
{
	t_instr new_instr;
	
	new_instr.type = type;
	if (index >= instr->content_len)
	{
		new_instr.arg = vec_init(sizeof(char *));
		new_instr.arg.rate = 8;
		vec_add(instr, &new_instr);
	}
	else if (vec_get_instr(instr, index)->type == 0)
		vec_get_instr(instr, index)->type = type;
	add_arg(instr, index, arg);
}

int	line_lexer(t_vec *line, t_vec *instr)
{
	ssize_t	i;
	int is_cmd;
	int cmd_index;

	is_cmd = 1;
	cmd_index = -1;
	i = -1;
	while (++i < (ssize_t) line->content_len)
		if (!(i == 0 || vec_get_char(line, i - 1) == 0))
			continue;
		else if (is_special_elem(vec_get_str(line, i)) != 0)
		{
			cmd_index++;
			is_cmd = 1;
			/* /!\ insert path /!\ */
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
	return (cmd_index + 1);
}

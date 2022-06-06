/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 13:01:39 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <stdlib.h>    /** getenv */

#include "line_lexer.h"

int		is_special_elem(char *elem);
void	set_bin_path(t_vec *line, int index);

static void	add_arg(size_t index, char *arg)
{
	vec_add_char_ptr(get_instr_arg(index), arg);
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
	else if (get_instr(index)->type == 0)
		get_instr(index)->type = type;
	add_arg(index, arg);
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
		if (!(i == 0 || get_cmd_char(i - 1) == 0))
			continue;
		else if (is_special_elem(get_cmd_str(i)) != 0)
		{
			cmd_index++;
			is_cmd = 1;
			/* /!\ insert path /!\ */
			new_instr(instr, cmd_index, 2, get_cmd_str(i));
		}
		else if (is_cmd)
		{
			cmd_index++;
			is_cmd = 0;
			new_instr(instr, cmd_index, 1, get_cmd_str(i));
		}
		else
			add_arg(cmd_index, get_cmd_str(i));
	return (cmd_index + 1);
}

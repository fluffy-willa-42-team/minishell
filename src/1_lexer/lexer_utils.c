/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:40:18 by awillems          #+#    #+#             */
/*   Updated: 2022/06/17 14:55:52 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_cmd_path(t_lexer_opt *opt, int index);

int	add_char(t_lexer_opt *opt, char *arg)
{
	vec_add(get_line(), arg);
	opt->index_line++;
	return (1);
}

void	add_arg(t_lexer_opt *opt)
{
	int	i;

	if (opt->index_instr == -1)
		vec_add_int(get_instr_arg(opt->nb_instr - 1), opt->index_line - 1);
	else
		vec_add_int(get_instr_arg(opt->index_instr), opt->index_line - 1);
	opt->new_instr = 0;
	opt->new_arg = 0;
	if (!opt->change_instr)
		return ;
	i = 1;
	while (i < opt->index_instr + 1
		&& get_instr(opt->nb_instr - i)->type != 1)
	{
		if (get_instr(opt->nb_instr - i)->type <= 3)
		{
			opt->index_instr = -1;
			opt->change_instr = 0;
			opt->new_instr = 1;
			return ;
		}
		i++;
	}
	opt->index_instr += 1 - i;
	opt->change_instr = 0;
}

void	new_instr(t_lexer_opt *opt, int type)
{
	t_instr	new_instr;

	new_instr.type = type;
	if (opt->nb_instr >= get_instr_list()->content_len)
	{
		new_instr.arg = vec_init(sizeof(int));
		new_instr.arg.rate = 8;
		vec_add(get_instr_list(), &new_instr);
	}
	else if (get_instr(opt->nb_instr)->type == 0)
		get_instr(opt->nb_instr)->type = type;
	opt->nb_instr++;
	add_arg(opt);
	opt->index_instr = -1;
}

void	add_instr_or_arg(t_lexer_opt *opt)
{
	if (opt->new_instr == 1)
	{
		new_instr(opt, 1);
		opt->new_instr = 0;
	}
	else if (opt->new_arg == 1)
	{
		add_arg(opt);
		opt->new_arg = 0;
	}
}

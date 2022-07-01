/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:40:18 by awillems          #+#    #+#             */
/*   Updated: 2022/07/01 11:38:33 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_parser.h"

void	add_cmd_path(t_parser_opt *opt, int index);

int	add_char(t_parser_opt *opt, char *arg)
{
	if (!vec_add(get_line(), arg))
	{
		opt->option |= ALLOC_FAIL;
		return (0);
	}
	opt->index_line++;
	return (1);
}

void	add_arg(t_parser_opt *opt)
{
	int	index;

	if (opt->index_instr == -1)
		index = opt->nb_instr - 1;
	else
		index = opt->index_instr;
	if (!vec_add_int(get_instr_arg(index), opt->index_line - 1))
	{
		opt->option |= ALLOC_FAIL;
		return ;
	}
	opt->option &= ~(NEW_INSTR | NEW_ARG);
	if (!(opt->option & CHANGE_INSTR) || opt->index_instr == -1)
		return ;
	while (opt->index_instr >= 0 && get_instr(opt->index_instr)->type != 1)
	{
		if (opt->index_instr == 0 || get_instr(opt->index_instr)->type <= 3)
			opt->option |= NEW_CMD;
		opt->index_instr--;
	}
	opt->option &= ~(CHANGE_INSTR);
}

void	new_instr(t_parser_opt *opt, int type)
{
	t_instr	new_instr;

	new_instr.type = type;
	new_instr.fds[0] = STDIN_FILENO;
	new_instr.fds[1] = STDOUT_FILENO;
	new_instr.err = 0;
	if (opt->nb_instr >= get_instr_list()->len)
	{
		new_instr.arg = (t_vec) vec_init(int);
		new_instr.arg.rate = 8;
		if (!vec_add(get_instr_list(), &new_instr))
		{
			opt->option |= ALLOC_FAIL;
			return ;
		}
	}
	else if (get_instr(opt->nb_instr)->type == 0)
		get_instr(opt->nb_instr)->type = type;
	opt->nb_instr++;
	add_arg(opt);
	opt->index_instr = -1;
	opt->option &= ~(NEW_INSTR | NEW_CMD);
}

void	add_instr_or_arg(t_parser_opt *opt)
{
	if (opt->option & NEW_ARG && opt->option & NEW_CMD)
	{
		opt->index_instr = -1;
		new_instr(opt, 1);
		opt->option &= ~(NEW_CMD);
	}
	else if (opt->option & NEW_INSTR)
		new_instr(opt, 1);
	else if (opt->option & NEW_ARG)
		add_arg(opt);
}

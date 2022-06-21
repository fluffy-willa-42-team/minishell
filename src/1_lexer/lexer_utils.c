/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:40:18 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 08:33:56 by awillems         ###   ########.fr       */
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
	if (opt->index_instr == -1)
		vec_add_int(get_instr_arg(opt->nb_instr - 1), opt->index_line - 1);
	else
		vec_add_int(get_instr_arg(opt->index_instr), opt->index_line - 1);
	opt->option = ~(NEW_INSTR | NEW_ARG) & opt->option;
	if (!(opt->option & CHANGE_INSTR) || opt->index_instr == -1)
		return ;
	while (opt->index_instr >= 0 && get_instr(opt->index_instr)->type != 1)
	{
		if (opt->index_instr == 0 || get_instr(opt->index_instr)->type <= 3)
			opt->option |= NEW_CMD;
		opt->index_instr--;
	}
	opt->option = ~(CHANGE_INSTR) & opt->option;
}

void	new_instr(t_lexer_opt *opt, int type)
{
	t_instr	new_instr;

	new_instr.type = type;
	new_instr.file_descriptor[0] = -1;
	new_instr.file_descriptor[1] = -1;
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
	opt->option = ~(NEW_INSTR | NEW_CMD) & opt->option;
}

void	add_instr_or_arg(t_lexer_opt *opt)
{
	if (opt->option & NEW_ARG && opt->option & NEW_CMD)
	{
		opt->index_instr = -1;
		new_instr(opt, 1);
		opt->option = ~(NEW_CMD) & opt->option;
	}
	else if (opt->option & NEW_INSTR)
		new_instr(opt, 1);
	else if (opt->option & NEW_ARG)
		add_arg(opt);
}

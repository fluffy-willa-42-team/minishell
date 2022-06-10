/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:40:18 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 10:01:33 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_arg(t_lexer_opt *opt, int index)
{
	printf("New Arg\n");
	vec_add_char_ptr(get_instr_arg(opt->nb_instr - 1), vec_get_str(get_line(), index));
	opt->new_instr = 0;
	opt->new_arg = 0;
}

void	new_instr(t_lexer_opt *opt, int type, int index)
{
	t_instr new_instr;
	
	printf("New Instr\n");
	new_instr.type = type;
	if ((size_t) opt->nb_instr >= get_instr_list()->content_len)
	{
		new_instr.arg = vec_init(sizeof(char *));
		new_instr.arg.rate = 8;
		vec_add(get_instr_list(), &new_instr);
	}
	else if (get_instr(opt->nb_instr)->type == 0)
		get_instr(opt->nb_instr)->type = type;
	opt->nb_instr++;
	add_arg(opt, index);
}

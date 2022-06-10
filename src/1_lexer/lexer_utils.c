/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:40:18 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 09:44:42 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_arg(size_t index, char *arg)
{
	vec_add_char_ptr(get_instr_arg(index), arg);
}

void	new_instr(size_t index, int type, char *arg, t_lexer_opt *opt)
{
	t_instr new_instr;
	
	new_instr.type = type;
	if (index >= get_instr_list()->content_len)
	{
		new_instr.arg = vec_init(sizeof(char *));
		new_instr.arg.rate = 8;
		vec_add(get_instr_list(), &new_instr);
	}
	else if (get_instr(index)->type == 0)
		get_instr(index)->type = type;
	opt->nb_instr++;
	add_arg(index, arg);
}

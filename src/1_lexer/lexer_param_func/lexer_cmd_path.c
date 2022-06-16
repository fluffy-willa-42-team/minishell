/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:48:49 by awillems          #+#    #+#             */
/*   Updated: 2022/06/16 22:02:35 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_cmd_path(t_lexer_opt *opt, int index_instr)
{
	const int	index = *((int *) vec_get(get_instr_arg(index_instr), 0));
	
	// printf("%ld - %ld -1 => %ld\n", opt->nb_instr, opt->index_instr, opt->nb_instr - opt->index_instr - 1);
	// if ()
	(void) opt;
	printf("VAR FINISHED => %s\n", vec_get_str(get_line(), index));
}
// mdr ; abc << def hij
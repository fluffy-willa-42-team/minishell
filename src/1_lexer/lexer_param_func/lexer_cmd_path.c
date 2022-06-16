/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:48:49 by awillems          #+#    #+#             */
/*   Updated: 2022/06/16 18:57:58 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_cmd_path(t_lexer_opt *opt)
{
	printf("VAR FINISHED : %lu\n", opt->nb_instr);
	vec_print(get_line());
	printf("=> %s\n", get_instr_arg_elem(opt->nb_instr - 1, 0));
}

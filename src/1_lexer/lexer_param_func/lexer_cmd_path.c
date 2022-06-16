/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:48:49 by awillems          #+#    #+#             */
/*   Updated: 2022/06/16 19:40:00 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_cmd_path(t_lexer_opt *opt, int index)
{
	(void) opt;
	printf("VAR FINISHED => %s\n",
		get_line()->buffer + *((int *) vec_get(get_instr_arg(index), 0)));
}

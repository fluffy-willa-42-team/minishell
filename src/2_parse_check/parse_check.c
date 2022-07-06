/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:55:46 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/30 09:50:26 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "vec_utils.h"

/**
 IND | CHAR | FUNCTION
-----0------0----------
   0 |    \ | bkslh
   1 |    ' | sglqot
   2 |    " | dblqot
   3 | $VAR | varsub
   4 |  ' ' | whtspc
   5 |   \t | whtspc
   6 |   \n | whtspc
   7 |   \v | whtspc
-----0------0----------
   DEFAULT  | dflt_char
*/

int	line_parse_check(int nb_instr)
{
	int	i;

	print_debug_sep("PARSER CHECK");
	i = 0;
	while (i < nb_instr)
	{
		if (get_instr(0) && get_instr(0)->type == 2)
			return (msh_return(0, 258, ERR_PARSE, __FUNCTION__));
		if ((get_instr(i)->type == 2 || get_instr(i)->type == 3)
			&& i + 1 < nb_instr
			&& (get_instr(i + 1)->type == 2 || get_instr(i + 1)->type == 3))
			return (msh_return(0, 258, ERR_PARSE, __FUNCTION__));
		i++;
	}
	print_debug("[OK]");
	return (1);
}

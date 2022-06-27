/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:55:46 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/27 09:25:50 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

void	line_pars_check(int nb_instr)
{
	if (!DEBUG_PRINT)
      return ;
   printf("\e[0;36m0=====-----	PARSER CHECK	-----=====0\n\e[0m");
	for (int i = 0; i < nb_instr; i++)
	{
		printf("[%d]\n", get_instr(i)->type);
	}
}

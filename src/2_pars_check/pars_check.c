/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:55:46 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/22 13:18:02 by mahadad          ###   ########.fr       */
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
	printf("\e[0;36m0=====-----	PARSER		-----=====0\n\e[0m");
	for (int i = 0; i < nb_instr; i++)
	{
		printf("[%d]\n", get_instr(i)->type);
	}
	printf("\e[0;36m0=====-----	PARSER		-----=====0\n\e[0m");
}

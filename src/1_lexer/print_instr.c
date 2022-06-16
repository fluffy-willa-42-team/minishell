/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:20:44 by awillems          #+#    #+#             */
/*   Updated: 2022/06/16 13:49:28 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "stdio.h"

void	print_instr(size_t len)
{
	printf("\nnb_instr: %lu,\n", get_instr_list()->content_len);
	printf("instr_list: [\n");
	for (size_t ind = 0; ind < len; ind++)
	{
		printf("\t{\n");
		printf("\t\ttype: %d,\n", get_instr(ind)->type);
		printf("\t\tcontent_len: %lu,\n", get_instr_arg(ind)->content_len);
		printf("\t\targ: [\n");
		for (size_t arg = 0; arg < get_instr_arg(ind)->content_len; arg++)
			printf("\t\t\t[%lu]: \"%s\",\n", arg, get_instr_arg_elem(ind, arg));
		printf("\t\t]\n");
		printf("\t},\n");
	}
	printf("]\n\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:20:44 by awillems          #+#    #+#             */
/*   Updated: 2022/06/20 12:34:47 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "stdio.h"

void	print_instr(size_t len)
{
	size_t	ind;
	size_t	arg;

	ind = -1;
	printf("[\n");
	while (++ind < len)
	{
		printf("    {\n");
		printf("        type: %d,\n", get_instr(ind)->type);
		printf("        nb arg: %lu,\n", get_instr_arg(ind)->content_len);
		printf("        arg: [\n");
		arg = -1;
		while (++arg < get_instr_arg(ind)->content_len)
			printf("            [%lu]: \"%s\",\n", arg,
				get_instr_arg_elem(ind, arg));
		printf("        ]\n");
		printf("    },\n");
	}
	printf("]\n");
}

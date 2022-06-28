/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:20:44 by awillems          #+#    #+#             */
/*   Updated: 2022/06/28 13:58:37 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "stdio.h"

void	print_instr(size_t len, int type)
{
	size_t	ind;
	size_t	arg;

	ind = -1;
	printf("[\n");
	while (++ind < len)
	{
		if (type == -1 || get_instr(ind)->type == type)
		{
		printf("    {\n");
		printf("        type: %d,\n", get_instr(ind)->type);
		printf("        fd: [%d, %d],\n",
			get_instr(ind)->fds[0],
			get_instr(ind)->fds[1]);
		printf("        err: %d,\n", get_instr(ind)->err);
		printf("        arg: [\n");
		arg = -1;
		while (++arg < get_instr_arg(ind)->len)
			printf("            \"%s\",\n", get_instr_arg_elem(ind, arg));
		printf("        ],\n");
		printf("    },\n");
		}
	}
	printf("]\n");
}

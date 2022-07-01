/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:20:44 by awillems          #+#    #+#             */
/*   Updated: 2022/07/01 14:58:20 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "stdio.h"

void	print_instr(size_t len, int type)
{
	size_t	ind;
	size_t	arg;

	if (!DEBUG_PRINT)
		return ;
	ind = -1;
	printf("[\n");
	while (++ind < len)
	{
		if (!(type == -1 || get_instr(ind)->type == type))
			continue ;
		printf("  {\n    type: %d,\n    fd: [%d, %d],\n    err: %d,\n    arg: [\n",
			get_instr(ind)->type, get_instr(ind)->fds[0],
			get_instr(ind)->fds[1], get_instr(ind)->err);
		arg = -1;
		while (++arg < get_instr_arg(ind)->len)
			printf("      \"%s\",\n", get_instr_arg_elem(ind, arg));
		printf("    ],\n  },\n");
	}
	printf("]\n");
}

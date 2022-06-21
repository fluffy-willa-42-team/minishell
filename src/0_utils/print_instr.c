/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:20:44 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 12:53:48 by mahadad          ###   ########.fr       */
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
		printf("        fd: [%d, %   d],\n",
			get_instr(ind)->file_descriptor[0],
			get_instr(ind)->file_descriptor[1]);
		printf("        arg: [\n");
		arg = -1;
		while (++arg < get_instr_arg(ind)->content_len)
			printf("            \"%s\",\n", get_instr_arg_elem(ind, arg));
		printf("        ],\n");
		printf("    },\n");
		}
	}
	printf("]\n");
}

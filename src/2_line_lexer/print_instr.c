/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:20:44 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 13:31:40 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include "stdio.h"

t_vec	*get_instr_arg(int index);

void	print_instr(void)
{
	t_instr	*instr;
	
	printf("[\n");
	for (size_t x = 0; x < g_data.lexed_instr.content_len; x++)
	{
		instr = vec_get_instr(&g_data.lexed_instr, x);
		printf("    {\n");
		printf("        type: %d,\n", instr->type);
		size_t x = 0;
		size_t y = instr->arg.content_len;
		printf("        content_len: %lu,\n", y);
		printf("        arg: [\n");
		while (y)
		{
			printf("            [%lu]: \"%s\",\n", x,
				vec_get_str_array(&instr->arg, x));
			y--;
			x++;
		}
		printf("        ],\n");
		printf("    },\n");
	}
	printf("]\n");
}

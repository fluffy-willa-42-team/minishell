/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:20:44 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 11:22:47 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include "stdio.h"

t_vec	*get_instr_arg(int index);

void	instr_debug(void)
{
	printf("[\n");
	for (size_t x = 0; x < g_data.lexed_instr.content_len; x++)
	{
		printf("    {\n");
		printf("        type: %d,\n", vec_get_instr(&g_data.lexed_instr, x)->type);
		size_t owo = 0;
		size_t uwu = get_instr_arg(x)->content_len;
		printf("        content_len: %lu,\n", uwu);
		printf("        arg: [\n");
		while (uwu)
		{
			printf("            [%lu]: \"%s\",\n",
					owo, vec_get_str_array(get_instr_arg(x), owo));
			uwu--;
			owo++;
		}
		printf("        ],\n");
		printf("    },\n");
	}
	printf("]\n");
}

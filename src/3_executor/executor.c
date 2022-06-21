/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:07:10 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 12:03:25 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

void	line_executor(void)
{
	printf("\e[0;36m0=====-----	EXECUTION	-----=====0\n\e[0m");
	for (size_t i = 0; i < get_instr_list()->content_len; i++)
	{
		if ( get_instr(i)->type != 1)
			continue ;
		size_t j = 0;
		printf("%d => [%s", get_instr(i)->file_descriptor[0], get_instr_arg_elem(i, j));
		j++;
		while (j < get_instr_arg(i)->content_len)
			printf(", %s", get_instr_arg_elem(i, j++));
		printf("] => %d\n", get_instr(i)->file_descriptor[1]);
		if (get_instr(i)->file_descriptor[0] != 0)
			close(get_instr(i)->file_descriptor[0]);
		if (get_instr(i)->file_descriptor[1] != 1)
			close(get_instr(i)->file_descriptor[1]);
	}
	printf("\e[0;36m0=====-----	END		-----=====0\n\e[0m");
}

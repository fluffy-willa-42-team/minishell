/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_line_exec_format.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:10:31 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 14:11:51 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <stdlib.h>    /** getenv */

#include "debug.h"

void	change_line_to_exec_format(t_vec *line, t_vec *instr)
{
	int i = 0;
	int	first_elem = 1;

	g_data.env_path = getenv("PATH");
	if (MSH_DEBUG)
		printf("[INFO] env updated, PATH:%s\n", g_data.env_path);
	
	(void) instr;
	while (i < line->len)
	{
		if (vec_get_char(line, i) != 0 && ( i == 0 || vec_get_char(line, i - 1) == 0))
		{
			// is_binary = is_bin();
			if (ft_strchr("<>|", vec_get_char(line, i)))
			{
				printf("PIPE ");//TODO make a function to handle the pipe and redirect stuff
				first_elem = 1;
			}
			else {//TODO populate the strcut
				if (first_elem)
				{
					printf("CMD ");
					first_elem = 0;
				}
				else
					printf("ARG ");
			}
			printf("=> [%s]\n", &line->buffer[i]);
		}
		i++;
	}
}
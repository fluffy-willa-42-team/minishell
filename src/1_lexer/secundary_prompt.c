/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secundary_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:48:04 by awillems          #+#    #+#             */
/*   Updated: 2022/06/16 14:07:06 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

#include <readline/readline.h>

void	secundary_prompt(char *prompt_start, char *delimitor)
{
	const size_t	len = ft_strlen(delimitor);
	char			*line_read;
	
	(void) delimitor;
	printf("delimitor : %s\n", delimitor);
	line_read = readline(prompt_start);
	while (line_read)
	{
		if (line_read && line_read[0])
		{
			printf("line_read : %s\n", line_read);
			if (len == ft_strlen(line_read)
					&& ft_strcmp(line_read, delimitor) == 0)
				break;
		}
		free(line_read);
		line_read = readline(prompt_start);
	}
	free(line_read);
}
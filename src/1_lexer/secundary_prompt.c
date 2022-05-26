/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secundary_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:40:25 by awillems          #+#    #+#             */
/*   Updated: 2022/05/26 12:17:13 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_debug.h"

#include "libft.h"
#include "vector_lib.h"
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"

void	msh_free(void *ptr);						/** @file msh_free.c */

void	secundary_prompt(t_vec *line, char *waiting_string)
{
	char	*line_read;

	(void) line;
	(void) waiting_string;
	line_read = readline(PROMPT_SECUND_START);
	while (line_read)
	{
		if (line_read[0])
		{
			printf("%s\n", line_read);
		}
		msh_free(line_read);
		line_read = readline(PROMPT_SECUND_START);
	}
	msh_free(line_read);
}

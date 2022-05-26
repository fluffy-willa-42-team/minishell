/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:44:08 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/26 10:10:13 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_debug.h"
#include "libft.h"

# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT_TXT "UwU $> "

/** @file msh_free.c */
void	msh_free(void *ptr);
/** @file set_sigaction.c */
void	set_sigaction(void);

void	msh_lexer(const char *line);

/**
 * @brief Start the prompt and set the signal action.
 */
void	msh_prompt(void)
{
	char	*line_read;

	set_sigaction();
	line_read = readline(PROMPT_TXT);
	while (line_read)
	{
		// `readline` wait a user imput from the prompt. Will return a string.
		if (line_read[0])
		{
			msh_lexer(line_read);
			add_history(line_read);
		}
		msh_free(line_read);
		line_read = readline(PROMPT_TXT);
	}
	msh_free(line_read);
}

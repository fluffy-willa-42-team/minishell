/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:44:08 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/25 11:13:03 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_prompt.h"
#include "msh_debug.h"
#include "libft.h"
#include "msh_free.h"

void	set_sigaction(void);

/**
 * @brief Start the prompt and set the signal action.
 */
void	msh_prompt(void)
{
	char	*line_read;

	set_sigaction();
	line_read = NULL;
	while (!line_read)
	{
		// `readline` wait a user imput from the prompt. Will return a string.
		line_read = readline(PROMPT_TXT);
		if (line_read)
		{
			// Check if readline dont return a EOF aka `C-D`
			if (line_read[0])
			{
				//TODO run paser function
				msh_lexer(line_read);
				if (MSH_DEBUG) printf("[%s]\n", line_read);
				add_history(line_read);
				msh_free(line_read);
			}
			else if (MSH_DEBUG)	printf("\nEmpty line\n");
		}
		else {
			if (MSH_DEBUG) printf("\n[NULL] line_read\n");
			return ;
		}
	}
}

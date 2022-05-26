/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:44:08 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/26 12:47:32 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_debug.h"

#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"
#include "msh_struct.h"

void	msh_free(void *ptr);					/** @file msh_free.c */
void	set_sigaction(void);					/** @file set_sigaction.c */
void	msh_lexer(const char *line);			/** @file msh_lexer.c */
void	close_opened_char(char *line);			/** @file close_opened_char.c */

/**
 * @brief Start the prompt and set the signal action.
 */
void	msh_prompt(void)
{
	char	*line_read;

	set_sigaction();
	line_read = readline(PROMPT_START);
	while (line_read)
	{
		if (line_read[0])
		{
			/**
			 * For online command add the raw line_read,
			 * If user use `"` or `'` multi line lexer need to return `line_read`
			 *  and the rest of the input buffer.
			 * 
			 * EXPECTED: 
			 *     add_history(msh_lexer(line_read);
			 *                    |
			 *                    -> if oneline return raw `line_read`, if multi line return strcat(`line_read`, `inputbuffer`);
			 */
			msh_lexer(line_read);
			add_history(line_read);
			vec_delete_content(&g_data.str_list);
		}
		msh_free(line_read);
		line_read = readline(PROMPT_START);
	}
	msh_free(line_read);
}

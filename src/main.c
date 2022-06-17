/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:36:24 by awillems          #+#    #+#             */
/*   Updated: 2022/06/17 11:12:41 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	set_sigaction(void);
void	line_lexer(char *line);

t_minishell	g_data;

/**
 * @brief Init the global var with all data.
 */
void	init_data(void)
{
	g_data.env_path = NULL;
	g_data.lexed_command = vec_init(sizeof(char));
	g_data.lexed_command.rate = 8;
	g_data.lexed_instr = vec_init(sizeof(t_instr));
	g_data.lexed_instr.rate = 8;
	g_data.tmp = vec_init(sizeof(char));
}

int	change_str_to_int(char **input, int *output)
{
	(void) input;
	*output = 0;
	return (1);
}

/**
 * @brief Empties
 * 
 */
void	empty_g_data(void)
{
	size_t	i;

	i = 0;
	vec_delete(get_line());
	while (i < g_data.lexed_instr.content_len)
	{
		vec_cast(get_instr_arg(i), sizeof(int), change_str_to_int);
		vec_delete(get_instr_arg(i));
		get_instr(i)->type = 0;
		i++;
	}
}

/**
 * @brief Inits Data and Start the lexed_command
 */
int	main(void)
{
	char	*line_read;

	init_data();
	set_sigaction();
	setbuf(stdout, NULL);
	line_read = readline(PROMPT_START);
	while (line_read)
	{
		if (line_read && line_read[0])
		{
			line_lexer(line_read);
			add_history(line_read);
			empty_g_data();
		}
		free(line_read);
		line_read = readline(PROMPT_START);
	}
	free(line_read);
	return (0);
}

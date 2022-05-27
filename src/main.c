/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:36:24 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 10:00:45 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	set_sigaction(void);
int 	interpret_line(char *line);

t_minishell	g_data;

/**
 * @brief Init the global var with all data.
 */
int	init_data(void)
{
	g_data.env_path = NULL;
	g_data.lexed_comands = vec_init(sizeof(char));
	if (!g_data.lexed_comands.buffer)
		return (0);
	return (1);
}

/**
 * @brief Inits Data and Start the prompt
 */
int	minishell(void)
{
	char *line_read;
	
	if (!init_data())
		return (0);
	set_sigaction();
	line_read = readline(PROMPT_START);
	while (line_read)
	{
		interpret_line(line_read);
		add_history(line_read);
		free(line_read);
		line_read = readline(PROMPT_START);
	}
	free(line_read);
	return (1);
}

int	main(void)
{
	return (!minishell());
}

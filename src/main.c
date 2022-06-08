/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:36:24 by awillems          #+#    #+#             */
/*   Updated: 2022/06/08 13:40:46 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	set_sigaction(void);
void	lexe_line(char *line);
void	exit_minishell(void);

t_minishell	g_data;

/**
 * @brief Init the global var with all data.
 */
void	init_data(void)
{
	g_data.env_path = NULL;
	g_data.lexed_command = vec_init(sizeof(char));
	g_data.lexed_instr = vec_init(sizeof(t_instr));
	g_data.lexed_instr.rate = 8;
	g_data.tmp = vec_init(sizeof(char));
}

/**
 * @brief Inits Data and Start the prompt
 */
int	main()
{
	char	*line_read;

	init_data();
	set_sigaction();
	line_read = readline(PROMPT_START);
	while (line_read)
	{
		if (line_read && line_read[0])
		{
			lexe_line(line_read);
			add_history(line_read);
		}
		free(line_read);
		line_read = readline(PROMPT_START);
	}
	free(line_read);
	return (0);
}

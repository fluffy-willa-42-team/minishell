/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:36:24 by awillems          #+#    #+#             */
/*   Updated: 2022/06/23 09:37:26 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	set_sigaction(void);
int		line_parser(char *line);
void	line_pars_check(int nb_instr);
void	line_file_manager(int nb_instr);
void	line_executor(void);

void	init_data(void);
void	empty_g_data(void);
void	free_g_data(void);

t_minishell	g_data;

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
			int nb_instr = line_parser(line_read);
			line_pars_check(nb_instr);
			line_file_manager(nb_instr);
			line_executor();
			add_history(line_read);
			empty_g_data();
		}
		free(line_read);
		line_read = readline(PROMPT_START);
	}
	free(line_read);
	free_g_data();
	return (0);
}

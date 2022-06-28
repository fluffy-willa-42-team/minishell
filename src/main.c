/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:36:24 by awillems          #+#    #+#             */
/*   Updated: 2022/06/28 15:14:47 by mahadad          ###   ########.fr       */
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

void	init_data(char **env);
void	empty_g_data(void);
void	free_g_data(void);

t_minishell	g_data;

/**
 * @brief Inits Data and Start the lexed_command
 */
int	main(int ac, char **av, char **env)
{
	char	*line_read;

	(void)ac;
	(void)av;
	init_data(env);
	set_sigaction();
	line_read = readline(PROMPT_START);
	while (line_read)
	{
		if (line_read && line_read[0])
		{
			g_data.cmd = line_read;
			int nb_instr = line_parser(line_read);
			if (!(nb_instr == 1 && (!get_instr_arg_elem(0, 0) || !get_instr_arg_elem(0, 0)[0])))
			{
				// line_pars_check(nb_instr);//TODO
				line_file_manager(nb_instr);
				line_executor();
			}
			add_history(line_read);
			empty_g_data();
		}
		free(line_read);
		line_read = readline(PROMPT_START);
	}
	free(line_read);
	free_g_data();
	printf("\n");
	return (0);
}

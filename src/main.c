/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:36:24 by awillems          #+#    #+#             */
/*   Updated: 2022/06/30 11:47:02 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	set_sigaction(void);
int		line_parser(char *line);
int		line_parse_check(int nb_instr);
void	line_file_manager(int nb_instr);
void	line_executor(void);

void	init_data(char **env);
void	empty_g_data(void);
void	free_g_data(void);

t_minishell	g_data;

void	do_line(char *line_read)
{
	int	nb_instr;

	g_data.cmd = line_read;
	nb_instr = line_parser(line_read);
	if (nb_instr == 1
		&& (!get_instr_arg_elem(0, 0) || !get_instr_arg_elem(0, 0)[0]))
		return ;
	if (!line_parse_check(nb_instr))
		return ;
	line_file_manager(nb_instr);
	line_executor();
}

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
			do_line(line_read);
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

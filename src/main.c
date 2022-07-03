/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:36:24 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 12:21:19 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <string.h>

void	set_sigaction(void);
int		line_parser(char *line);
int		line_parse_check(int nb_instr);
void	line_file_manager(int nb_instr);
void	line_executor(pid_t pid, size_t i, int index, int status);

void	print_instr(size_t len, int type);

void	init_data(char **env);
void	empty_g_data(void);
void	free_g_data(void);

t_minishell	g_data;

static int	setup_prompt_start(t_vec *vec, int ac, char **av)
{
	if (ac > 1)
	{
		if (!vec_fill(vec, MULTI, 3, "(", av[1], ")> "))
			return (0);
	}
	else if (!vec_fill(vec, DEFAULT, PROMPT_START))
		return (0);
	return (1);
}

static void	parser_debug(int nb_instr)
{
	print_debug_sep("BUFFER");
	if (DEBUG_PRINT)
		vec_print(get_line());
	print_debug_sep("STRUCTURE");
	print_instr(nb_instr, -1);
}

void	do_line(char *line_read)
{
	int	nb_instr;

	g_data.cmd = line_read;

	nb_instr = line_parser(line_read);
	if (nb_instr == -1)
		return ;
	parser_debug(nb_instr);
	if (nb_instr == 1
		&& (!get_instr_arg_elem(0, 0) || !get_instr_arg_elem(0, 0)[0]))
		return ;
	if (!line_parse_check(nb_instr))
		return ;
	line_file_manager(nb_instr);
	line_executor(0, -1, 0, 0);
}

/**
 * @brief Inits Data and Start the lexed_command
 */
int	main(int ac, char **av, char **env)
{
	char	*line_read;

	print_debug_sep("DEBUG ENABLE");
	g_data.prompt_start = (t_vec) vec_init(char);
	if (!setup_prompt_start(&prompt_start, ac, av))
		return (msh_exit(0, ENOMEM, strerror(ENOMEM), __FUNCTION__));
	init_data(env);
	set_sigaction();
	line_read = readline(prompt_start.buffer);
	while (line_read)
	{
		if (line_read && line_read[0])
		{
			do_line(line_read);
			add_history(line_read);
			empty_g_data();
		}
		free(line_read);
		line_read = readline(prompt_start.buffer);
	}
	free(line_read);
	free_g_data();
	return (0);
}

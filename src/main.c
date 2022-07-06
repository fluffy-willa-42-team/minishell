/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:36:24 by awillems          #+#    #+#             */
/*   Updated: 2022/07/06 11:15:22 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
#include <lib_str.h>

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <string.h>

int		line_parser(char *line);
int		line_parse_check(int nb_instr);
void	line_file_manager(int nb_instr);
void	line_executor(pid_t pid, int status, size_t i, int index);

int		setup_prompt_start(t_vec *vec, int ac, char **av);
void	set_sigaction(int is_child);
void	init_data(char **env);
void	parser_debug(int nb_instr);

void	empty_g_data(void);
void	free_g_data(int free_line);

t_minishell	g_data;

void	do_line(char *line_read)
{
	int	nb_instr;

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
	line_executor(0, 0, -1, 0);
}

void	exec_line(void)
{
	do_line(g_data.line_read);
	empty_g_data();
	while (g_data.parsing_index != 0)
	{
		g_data.parsing_index++;
		do_line(g_data.line_read);
		empty_g_data();
	}
}

void	start_prompt(void)
{
	set_sigaction(0);
	g_data.line_read = readline(g_data.prompt_start.buffer);
	while (g_data.line_read)
	{
		if (g_data.line_read && g_data.line_read[0])
		{
			exec_line();
			add_history(g_data.line_read);
		}
		free(g_data.line_read);
		g_data.line_read = readline(g_data.prompt_start.buffer);
	}
}

/**
 * @brief Inits Data and Start the lexed_command
 */
int	main(int ac, char **av, char **env)
{
	print_debug_sep("DEBUG ENABLE");
	g_data.prompt_start = vec_init(sizeof(char));
	g_data.prompt_start.exit_func = vec_exit_func;
	if (!setup_prompt_start(&g_data.prompt_start, ac, av))
		return (msh_return(0, ENOMEM, strerror(ENOMEM), __FUNCTION__));
	init_data(env);
	start_prompt();
	free_g_data(1);
	return (0);
}

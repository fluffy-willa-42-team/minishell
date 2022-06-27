/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_data_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:20:32 by awillems          #+#    #+#             */
/*   Updated: 2022/06/27 09:56:12 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

/**
 * @brief Init the global var with all data.
 */
void	init_data(void)
{
	g_data.env_path = NULL;
	g_data.lexed_command = vec_init(sizeof(char));
	g_data.lexed_command.rate = 8;
	vec_resize(&g_data.lexed_command);
	g_data.lexed_instr = vec_init(sizeof(t_instr));
	g_data.lexed_instr.rate = 8;
	g_data.tmp = vec_init(sizeof(char));
	g_data.last_exit_code = 0;
	g_data.cmd = NULL;
	g_data.code_buf = 0;
	g_data.pipe_buf[0] = -2;
	g_data.pipe_buf[1] = -2;
}

static int	change_str_to_int(char **input, int *output)
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
		if (get_instr(i)->fds[0] != 0)
			close(get_instr(i)->fds[0]);
		if (get_instr(i)->fds[1] != 1)
			close(get_instr(i)->fds[1]);
		get_instr(i)->fds[0] = STDIN_FILENO;
		get_instr(i)->fds[1] = STDOUT_FILENO;
		i++;
	}
	g_data.cmd = NULL;
}

/**
 * @brief Frees
 * 
 */
void	free_g_data(void)
{
	size_t	i;

	i = 0;
	vec_destroy(&g_data.tmp);
	vec_destroy(get_line());
	while (i < g_data.lexed_instr.content_len)
	{
		if (get_instr(i)->fds[0] != 0)
			close(get_instr(i)->fds[0]);
		if (get_instr(i)->fds[1] != 1)
			close(get_instr(i)->fds[1]);
		vec_destroy(get_instr_arg(i));
		i++;
	}
	vec_destroy(get_instr_list());
}


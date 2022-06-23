/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_data_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:20:32 by awillems          #+#    #+#             */
/*   Updated: 2022/06/22 15:10:22 by mahadad          ###   ########.fr       */
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
	g_data.lexed_instr = vec_init(sizeof(t_instr));
	g_data.lexed_instr.rate = 8;
	g_data.tmp = vec_init(sizeof(char));
	g_data.last_exit_code = 0;
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
		get_instr(i)->file_descriptor[0] = STDIN_FILENO;
		get_instr(i)->file_descriptor[1] = STDOUT_FILENO;
		i++;
	}
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
		vec_destroy(get_instr_arg(i));
		i++;
	}
	vec_destroy(get_instr_list());
}


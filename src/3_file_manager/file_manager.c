/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:06:58 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 18:22:31 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"
#include "vec_utils.h"

void	print_instr(size_t len, int type);

t_fd_manager_param	get_func_file_manager(int type)
{
	const t_fd_manager_param	func[] = {
		cmd_instr, cmd_redirect, cmd_separator,
		redir_in_file, redir_in_write, redir_out_file, redir_out_conca
	};
	const int					param[] = {
		CMD_INSTR, CMD_REDIRECT, CMD_SEPARATOR,
		REDIR_IN_FILE, REDIR_IN_WRITE, REDIR_OUT_FILE, REDIR_OUT_CONCA
	};
	int							i;

	i = 0;
	while (i < 7)
	{
		if (type == param[i])
			return (func[i]);
		i++;
	}
	return (cmd_instr);
}

/**
 * @brief Set the `fds` to defaut value `-2`.
 * 
 * @param nb_instr 
 */
void	line_file_manager(int nb_instr)
{
	int	(*pipe_ptr)[2];
	int	*code_ptr;
	int	i;

	code_ptr = &g_data.code_buf;
	pipe_ptr = &g_data.pipe_buf;
	print_debug_sep("FILE MANAGER");
	i = 0;
	while (i < nb_instr)
	{
		(get_func_file_manager(get_instr(i)->type))(i, &pipe_ptr, &code_ptr);
		i++;
	}
	if (pipe_ptr == &g_data.pipe_buf)
	{
		close_fd(&pipe_ptr, 0);
		close_fd(&pipe_ptr, 1);
	}
	print_debug_sep("STRUCTURE");
	print_instr(nb_instr, 1);
}

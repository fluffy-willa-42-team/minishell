/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:06:58 by awillems          #+#    #+#             */
/*   Updated: 2022/06/22 10:34:47 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"

void	print_instr(size_t len, int type);

t_fd_manager_param	get_func_file_manager(int type)
{
	const t_fd_manager_param	func[7] = {
		cmd_instr, cmd_redirect, cmd_separator,
		redir_in_file, redir_in_write, redir_out_file, redir_out_conca
	};
	const int					param[7] = {
		CMD_INSTR, CMD_REDIRECT, CMD_SEPARATOR,
		REDIR_IN_FILE, REDIR_IN_WRITE, REDIR_OUT_FILE, REDIR_OUT_CONCA
	};
	for (int i = 0; i < 7; i++)
		if (type == param[i])
			return (func[i]);
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

	code_ptr = &g_data.code_buf;
	pipe_ptr = &g_data.pipe_buf;
	printf("\e[0;36m0=====-----	FILE MANAGER	-----=====0\n\e[0m");
	for (int i = 0; i < nb_instr; i++)
		get_func_file_manager(get_instr(i)->type)(i, &pipe_ptr, &code_ptr);
	if (pipe_ptr == &g_data.pipe_buf)
	{
		close_fd(&pipe_ptr, 0);
		close_fd(&pipe_ptr, 1);
	}
	printf("\e[0;36m0=====-----	STRUCTURE	-----=====0\n\e[0m");
	print_instr(nb_instr, 1);
}

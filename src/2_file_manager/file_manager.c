/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:06:58 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 09:26:46 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"

void	print_instr(size_t len);

t_fd_manager_param	get_func_file_manager(int type)
{
	t_fd_manager_param func[7] = {
		cmd_instr, cmd_redirect, cmd_separator,
		redir_in_file, redir_in_write, redir_out_file, redir_out_conca
	};
	int	param[7] = {
		CMD_INSTR, CMD_REDIRECT, CMD_SEPARATOR,
		REDIR_IN_FILE, REDIR_IN_WRITE, REDIR_OUT_FILE, REDIR_OUT_CONCA
	};
	for (int i = 0; i < 7; i++)
		if (type == param[i])
			return (func[i]);
	return (cmd_instr);
}

void	line_file_manager(int nb_instr)
{
	int	fds[2] = {-1, -1};
	int	(*pipe_ptr)[2]= &fds;

	printf("\e[0;36m0=====-----	FILE MANAGER	-----=====0\n\e[0m");
	for (size_t i = 0; i < get_instr_list()->content_len; i++)
	{
		get_func_file_manager(get_instr(i)->type)(&pipe_ptr, i, &fds);
	}
	printf("\e[0;36m0=====-----	STRUCTURE	-----=====0\n\e[0m");
	print_instr(nb_instr);
}

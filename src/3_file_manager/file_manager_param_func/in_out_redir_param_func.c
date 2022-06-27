/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_redir_param_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:19:09 by awillems          #+#    #+#             */
/*   Updated: 2022/06/27 09:25:50 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"
#include <errno.h>

/**
 * @brief 
*/
void	redir_in_file(int instr_index, int (**pipe_ptr)[2], int **code_ptr)
{
	int	new_fd;
	
	if (**code_ptr != 0)
		return ;
	if (DEBUG_PRINT)
		printf("REDIR IN FILE\n");
	new_fd = open(get_instr_arg_elem(instr_index, 1), O_RDONLY);
	if (new_fd == -1)
		**code_ptr = errno;
	close_fd(pipe_ptr, 0);
	(**pipe_ptr)[0] = new_fd;
}

/**
 * @brief Will set the `fd` for the out file. /!\  We dont check the return
 *        value of `open(2)`, the executor will handle bad `fd`.
 */
void	redir_out_file(int instr_index, int (**pipe_ptr)[2], int **code_ptr)
{
	int	new_fd;

	if (**code_ptr != 0)
		return ;
	if (DEBUG_PRINT)
		printf("REDIR OUT FILE\n");
	new_fd = open(get_instr_arg_elem(instr_index, 1), O_WRONLY | O_TRUNC);
	if (new_fd == -1 && errno == ENOENT)
		new_fd = open(get_instr_arg_elem(instr_index, 1), O_CREAT, 0666);
	if (new_fd == -1)
		**code_ptr = errno;
	close_fd(pipe_ptr, 1);
	(**pipe_ptr)[1] = new_fd;
}

void	redir_out_conca(int instr_index, int (**pipe_ptr)[2], int **code_ptr)
{
	int	new_fd;

	if (**code_ptr != 0)
		return ;
	if (DEBUG_PRINT)
		printf("REDIR OUT CONCA\n");
	new_fd = open(get_instr_arg_elem(instr_index, 1), O_WRONLY | O_APPEND);
	if (new_fd == -1 && errno == ENOENT)
		new_fd = open(get_instr_arg_elem(instr_index, 1), O_CREAT, 0666);
	if (new_fd == -1)
		**code_ptr = errno;
	close_fd(pipe_ptr, 1);
	(**pipe_ptr)[1] = new_fd;
}

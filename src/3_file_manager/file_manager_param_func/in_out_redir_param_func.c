/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_redir_param_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:19:09 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 12:56:19 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"

/**
 * @brief 
*/
int	redir_in_file(int instr_index, int (**pipe_ptr)[2], int *code_ptr)
{
	const int	new_fd = open(get_instr_arg_elem(instr_index, 1), O_RDONLY);

	printf("REDIR IN FILE\n");
	(void) code_ptr;
	close_fd(pipe_ptr, 0);
	(**pipe_ptr)[0] = new_fd;
	return (1);
}

/**
 * @brief Will set the `fd` for the out file. /!\  We dont check the return
 *        value of `open(2)`, the executor will handle bad `fd`.
 */
int	redir_out_file(int instr_index, int (**pipe_ptr)[2], int *code_ptr)
{
	int	new_fd;

	printf("REDIR OUT FILE\n");
	(void) code_ptr;
	new_fd = open(get_instr_arg_elem(instr_index, 1), O_WRONLY | O_TRUNC);
	if (new_fd == -1)
		new_fd = open(get_instr_arg_elem(instr_index, 1), O_CREAT, 0666);
	close_fd(pipe_ptr, 1);
	(**pipe_ptr)[1] = new_fd;
	return (1);
}

int	redir_out_conca(int instr_index, int (**pipe_ptr)[2], int *code_ptr)
{
	int	new_fd;

	printf("REDIR OUT CONCA\n");
	(void) code_ptr;
	new_fd = open(get_instr_arg_elem(instr_index, 1), O_WRONLY | O_APPEND);
	if (new_fd == -1)
		new_fd = open(get_instr_arg_elem(instr_index, 1), O_CREAT, 0666);
	close_fd(pipe_ptr, 1);
	(**pipe_ptr)[1] = new_fd;
	return (1);
}

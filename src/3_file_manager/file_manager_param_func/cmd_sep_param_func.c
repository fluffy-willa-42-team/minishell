/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sep_param_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:18:35 by awillems          #+#    #+#             */
/*   Updated: 2022/06/23 11:14:45 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"

/**
 * @brief Will change the pipe_ptr to the pipe pointer in the command
 * instruction and move the value from the initial value of pipe_ptr.
 */
void	cmd_instr(int instr_index, int (**pipe_ptr)[2], int **code_ptr)
{
	printf("CMD INSTR\n");
	move_buf(pipe_ptr, 0, instr_index);
	move_buf(pipe_ptr, 1, instr_index);
	get_instr(instr_index)->err = **code_ptr;
	**code_ptr = 0;
	*pipe_ptr = &get_instr(instr_index)->fds;
	*code_ptr = &get_instr(instr_index)->err;
}

/**
 * @brief Will reset the pipe pointer back to the tempory pipe_temp.
 */
void	cmd_redirect(int instr_index, int (**pipe_ptr)[2], int **code_ptr)
{
	printf("CMD REDIRECT\n");
	pipe(get_instr(instr_index)->fds);
	if (get_instr(instr_index)->fds[1] == 1)
		(**pipe_ptr)[1] = get_instr(instr_index)->fds[1];
	else
		close(get_instr(instr_index)->fds[1]);
	*pipe_ptr = &g_data.pipe_buf;
	*code_ptr = &g_data.code_buf;
	(**pipe_ptr)[0] = get_instr(instr_index)->fds[0];
}

/**
 * @brief Will reset the pipe pointer back to the tempory pipe_temp.
 */
void	cmd_separator(int instr_index, int (**pipe_ptr)[2], int **code_ptr)
{
	printf("CMD SEPARATOR\n");
	(void) instr_index;
	*pipe_ptr = &g_data.pipe_buf;
	*code_ptr = &g_data.code_buf;
}

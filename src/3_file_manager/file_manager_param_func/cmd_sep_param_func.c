/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sep_param_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:18:35 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 13:27:18 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"

/**
 * @brief Will change the pipe_ptr to the pipe pointer in the command
 * instruction and move the value from the initial value of pipe_ptr.
 */
int	cmd_instr(int (**pipe_ptr)[2], int instr_index, int (*pipe_temp)[2])
{
	printf("CMD INSTR\n");
	(void) pipe_temp;
	move_buf(pipe_ptr, 0, instr_index);
	move_buf(pipe_ptr, 1, instr_index);
	*pipe_ptr = &get_instr(instr_index)->file_descriptor;
	return (1);
}

/**
 * @brief Will reset the pipe pointer back to the tempory pipe_temp.
 */
int	cmd_redirect(int (**pipe_ptr)[2], int instr_index, int (*pipe_temp)[2])
{
	printf("CMD REDIRECT\n");
	pipe(get_instr(instr_index)->file_descriptor);
	(**pipe_ptr)[1] = get_instr(instr_index)->file_descriptor[1];
	*pipe_ptr = pipe_temp;
	(**pipe_ptr)[0] = get_instr(instr_index)->file_descriptor[0];
	return (1);
}

/**
 * @brief Will reset the pipe pointer back to the tempory pipe_temp.
 */
int	cmd_separator(int (**pipe_ptr)[2], int instr_index, int (*pipe_temp)[2])
{
	printf("CMD SEPARATOR\n");
	(void) instr_index;
	*pipe_ptr = pipe_temp;
	return (1);
}

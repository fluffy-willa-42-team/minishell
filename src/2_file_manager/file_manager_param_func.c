/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager_param_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:11:01 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 09:01:07 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"

/**
 * @brief Will change the pipe_ptr to the pipe pointer in the command
 * instruction and move the value from the initial value of pipe_ptr.
 */
int	cmd_instr(int (**pipe_ptr)[2], int instr_index, int (**pipe_temp)[2])
{
	(void) pipe_temp;
	if ((**pipe_ptr)[0] != -1)
		get_instr(instr_index)->file_descriptor[0] = (**pipe_ptr)[0];
	if ((**pipe_ptr)[1] != -1)
		get_instr(instr_index)->file_descriptor[1] = (**pipe_ptr)[1];
	*pipe_ptr = &get_instr(instr_index)->file_descriptor;
	printf("[%d] [%d, %d]\tCMD INSTR\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

/**
 * @brief Will reset the pipe pointer back to the tempory pipe_temp.
 */
int	cmd_redirect(int (**pipe_ptr)[2], int instr_index, int (**pipe_temp)[2])
{
	(**pipe_temp)[0] = (**pipe_temp)[1];
	(**pipe_temp)[1] = STDOUT_FILENO;
	pipe_ptr = pipe_temp;
	printf("[%d] [%d, %d]\tCMD REDIRECT\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

/**
 * @brief Will reset the pipe pointer back to the tempory pipe_temp.
 */
int	cmd_separator(int (**pipe_ptr)[2], int instr_index, int (**pipe_temp)[2])
{
	(**pipe_temp)[0] = STDIN_FILENO;
	(**pipe_temp)[1] = STDOUT_FILENO;
	pipe_ptr = pipe_temp;
	printf("[%d] [%d, %d]\tCMD SEPARATOR\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

int	redir_in_file(int (**pipe_ptr)[2], int instr_index, int (**pipe_temp)[2])
{
	(void) pipe_temp;
	(**pipe_ptr)[0] = 3;
	printf("[%d] [%d, %d]\tREDIR IN FILE\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

int	redir_in_write(int (**pipe_ptr)[2], int instr_index, int (**pipe_temp)[2])
{
	(void) pipe_temp;
	(**pipe_ptr)[0] = 5;
	printf("[%d] [%d, %d]\tREDIR IN WRITE\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

int	redir_out_file(int (**pipe_ptr)[2], int instr_index, int (**pipe_temp)[2])
{
	(void) pipe_temp;
	(**pipe_ptr)[1] = 4;
	printf("[%d] [%d, %d]\tREDIR OUT FILE\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

int	redir_out_conca(int (**pipe_ptr)[2], int instr_index, int (**pipe_temp)[2])
{
	(void) pipe_temp;
	(**pipe_ptr)[1] = 6;
	printf("[%d] [%d, %d]\tREDIR OUT CONCA\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager_param_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:11:01 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 10:26:51 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"

/**
 * @brief Will change the pipe_ptr to the pipe pointer in the command
 * instruction and move the value from the initial value of pipe_ptr.
 */
int	cmd_instr(int (**pipe_ptr)[2], int (*pipe_temp)[2], int instr_index)
{
	printf("CMD INSTR\n");
	if ((**pipe_ptr)[0] != -2)
		get_instr(instr_index)->file_descriptor[0] = (**pipe_ptr)[0];
	if ((**pipe_ptr)[1] != -2)
		get_instr(instr_index)->file_descriptor[1] = (**pipe_ptr)[1];
	*pipe_ptr = &get_instr(instr_index)->file_descriptor;
	(void) pipe_temp;
	return (1);
}

/**
 * @brief Will reset the pipe pointer back to the tempory pipe_temp.
 */
int	cmd_redirect(int (**pipe_ptr)[2], int (*pipe_temp)[2])
{
	printf("CMD REDIRECT\n");
	(**pipe_ptr)[1] = 11;
	*pipe_ptr = pipe_temp;
	(**pipe_ptr)[0] = 10;
	return (1);
}

/**
 * @brief Will reset the pipe pointer back to the tempory pipe_temp.
 */
int	cmd_separator(int (**pipe_ptr)[2], int (*pipe_temp)[2])
{
	printf("CMD SEPARATOR\n");
	*pipe_ptr = pipe_temp;
	(**pipe_ptr)[0] = -2;
	(**pipe_ptr)[1] = -2;
	return (1);
}

int	redir_in_file(int (**pipe_ptr)[2])
{
	printf("REDIR IN FILE\n");
	(**pipe_ptr)[0] = 3;
	return (1);
}

int	redir_in_write(int (**pipe_ptr)[2])
{
	printf("REDIR IN WRITE\n");
	(**pipe_ptr)[0] = 5;
	return (1);
}

int	redir_out_file(int (**pipe_ptr)[2])
{
	printf("REDIR OUT FILE\n");
	(**pipe_ptr)[1] = 4;
	return (1);
}

int	redir_out_conca(int (**pipe_ptr)[2])
{
	printf("REDIR OUT CONCA\n");
	(**pipe_ptr)[1] = 6;
	return (1);
}

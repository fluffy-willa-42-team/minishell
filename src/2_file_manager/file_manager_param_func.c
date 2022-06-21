/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager_param_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:11:01 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 08:22:17 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"

int	cmd_instr(int (**pipe_ptr)[2], int instr_index)
{
	printf("[%d] [%d, %d]\tCMD INSTR\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	*pipe_ptr = &get_instr(instr_index)->file_descriptor;
	return (1);
}

int	cmd_redirect(int (**pipe_ptr)[2], int instr_index)
{
	printf("[%d] [%d, %d]\tCMD REDIRECT\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

int	cmd_separator(int (**pipe_ptr)[2], int instr_index)
{
	printf("[%d] [%d, %d]\tCMD SEPARATOR\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

int	redir_in_file(int (**pipe_ptr)[2], int instr_index)
{
	printf("[%d] [%d, %d]\tREDIR IN FILE\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

int	redir_in_write(int (**pipe_ptr)[2], int instr_index)
{
	printf("[%d] [%d, %d]\tREDIR IN WRITE\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

int	redir_out_file(int (**pipe_ptr)[2], int instr_index)
{
	printf("[%d] [%d, %d]\tREDIR OUT FILE\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

int	redir_out_conca(int (**pipe_ptr)[2], int instr_index)
{
	printf("[%d] [%d, %d]\tREDIR OUT CONCA\n", instr_index, (**pipe_ptr)[0], (**pipe_ptr)[1]);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager_param_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:11:01 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 08:12:28 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"

int	cmd_instr(int (*pipe_ptr)[2])
{
	printf("[%d, %d] CMD INSTR\n", (*pipe_ptr)[0], (*pipe_ptr)[1]);
	return (1);
}

int	cmd_redirect(int (*pipe_ptr)[2])
{
	printf("[%d, %d] CMD REDIRECT\n", (*pipe_ptr)[0], (*pipe_ptr)[1]);
	return (1);
}

int	cmd_separator(int (*pipe_ptr)[2])
{
	printf("[%d, %d] CMD SEPARATOR\n", (*pipe_ptr)[0], (*pipe_ptr)[1]);
	return (1);
}

int	redir_in_file(int (*pipe_ptr)[2])
{
	printf("[%d, %d] REDIR IN FILE\n", (*pipe_ptr)[0], (*pipe_ptr)[1]);
	return (1);
}

int	redir_in_write(int (*pipe_ptr)[2])
{
	printf("[%d, %d] REDIR IN WRITE\n", (*pipe_ptr)[0], (*pipe_ptr)[1]);
	return (1);
}

int	redir_out_file(int (*pipe_ptr)[2])
{
	printf("[%d, %d] REDIR OUT FILE\n", (*pipe_ptr)[0], (*pipe_ptr)[1]);
	return (1);
}

int	redir_out_conca(int (*pipe_ptr)[2])
{
	printf("[%d, %d] REDIR OUT CONCA\n", (*pipe_ptr)[0], (*pipe_ptr)[1]);
	return (1);
}

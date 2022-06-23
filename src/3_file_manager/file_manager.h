/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:11:26 by awillems          #+#    #+#             */
/*   Updated: 2022/06/23 12:09:43 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANAGER_H
# define FILE_MANAGER_H

/* ************************************************************************** */

# include "minishell.h"
# include "vec_utils.h"
# include "lib_str.h"
# include "lib_put_fd.h"
# include <fcntl.h>

/* ************************************************************************** */

typedef int	(*t_fd_manager_param)();

/* ************************************************************************** */

void	close_fd(int (**pipe_ptr)[2], int index);
void	move_buf(int (**pipe_ptr)[2], int index, int instr_index);

int	cmd_instr(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
int	cmd_redirect(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
int	cmd_separator(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
int	redir_in_file(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
int	redir_in_write(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
int	redir_out_file(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
int	redir_out_conca(int instr_index, int (**pipe_ptr)[2], int **code_ptr);

/* ************************************************************************** */

#endif

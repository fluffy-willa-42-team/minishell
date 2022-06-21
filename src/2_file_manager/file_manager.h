/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:11:26 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 08:26:13 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANAGER_H
# define FILE_MANAGER_H

/* ************************************************************************** */

# include "minishell.h"
# include "vec_utils.h"

/* ************************************************************************** */

typedef int	(*t_fd_manager_param)();

/* ************************************************************************** */

int	cmd_instr(int (**pipe_ptr)[2], int instr_index, int (*pipe_temp)[2]);
int	cmd_redirect(int (**pipe_ptr)[2], int instr_index, int (*pipe_temp)[2]);
int	cmd_separator(int (**pipe_ptr)[2], int instr_index, int (*pipe_temp)[2]);
int	redir_in_file(int (**pipe_ptr)[2], int instr_index, int (*pipe_temp)[2]);
int	redir_in_write(int (**pipe_ptr)[2], int instr_index, int (*pipe_temp)[2]);
int	redir_out_file(int (**pipe_ptr)[2], int instr_index, int (*pipe_temp)[2]);
int	redir_out_conca(int (**pipe_ptr)[2], int instr_index, int (*pipe_temp)[2]);

/* ************************************************************************** */

#endif

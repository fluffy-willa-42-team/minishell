/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:11:26 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 12:41:06 by mahadad          ###   ########.fr       */
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

void	close_fd(int (**pipe_ptr)[2], int index);
void	move_buf(int (**pipe_ptr)[2], int index, int instr_index);

int	cmd_instr(int (**pipe_ptr)[2], int instr_index, int (*p_ptr)[2]);
int	cmd_redirect(int (**pipe_ptr)[2], int instr_index, int (*p_ptr)[2]);
int	cmd_separator(int (**pipe_ptr)[2], int instr_index, int (*p_ptr)[2]);
int	redir_in_file(int (**pipe_ptr)[2], int instr_index);
int	redir_in_write(int (**pipe_ptr)[2], int instr_index);
int	redir_out_file(int (**pipe_ptr)[2], int instr_index);
int	redir_out_conca(int (**pipe_ptr)[2], int instr_index);

/* ************************************************************************** */

#endif

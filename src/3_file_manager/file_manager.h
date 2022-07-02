/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:11:26 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 17:45:35 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANAGER_H
# define FILE_MANAGER_H

/* ************************************************************************** */

/* ************************************************************************** */

typedef void	(*t_fd_manager_param)();

/* ************************************************************************** */

void	close_fd(int (**pipe_ptr)[2], int index);
void	move_buf(int (**pipe_ptr)[2], int index, int instr_index);

void	cmd_instr(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
void	cmd_redirect(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
void	cmd_separator(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
void	redir_in_file(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
void	redir_in_write(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
void	redir_out_file(int instr_index, int (**pipe_ptr)[2], int **code_ptr);
void	redir_out_conca(int instr_index, int (**pipe_ptr)[2], int **code_ptr);

/* ************************************************************************** */

#endif

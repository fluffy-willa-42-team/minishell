/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:11:26 by awillems          #+#    #+#             */
/*   Updated: 2022/06/20 16:12:54 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANAGER_H
# define FILE_MANAGER_H

# include "minishell.h"
# include "vec_utils.h"

/* ************************************************************************** */

int	cmd_instr(void);
int	cmd_redirect(void);
int	cmd_separator(void);
int	redir_in_file(void);
int	redir_in_write(void);
int	redir_out_file(void);
int	redir_out_conca(void);

/* ************************************************************************** */

#endif

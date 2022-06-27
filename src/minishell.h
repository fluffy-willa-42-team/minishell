/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:52 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/27 10:54:53 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */

# define PROMPT_START           "(o_O)> "
# define SECUNDARY_PROMPT_START "> "

# define CMD_INSTR				1
# define CMD_REDIRECT			2
# define CMD_SEPARATOR			3
# define REDIR_IN_FILE			4
# define REDIR_IN_WRITE			5
# define REDIR_OUT_FILE			6
# define REDIR_OUT_CONCA		7

// https://github.com/bminor/bash/blob/f3a35a2d601a55f337f8ca02a541f8c033682247/shell.h#L66
# define EX_NOTFOUND            127


# ifndef DEBUG_PRINT
#  define DEBUG_PRINT 0
# endif


/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include "vector_lib.h"

/* ************************************************************************** */

typedef struct s_minishell
{
	char	*env_path;
	t_vec	lexed_command;
	t_vec	lexed_instr;
	t_vec	tmp;
    int     last_exit_code;
    char    *cmd;
    int 	pipe_buf[2];
	int	 	code_buf;
}				t_minishell;

/**
 * Json like representation.
{
    [
    char *arg[
        char *arg0, // ptr to the bin path and name
        char *arg1, // first arg
        char *arg2, // segond arg
        char *....,
        ],
    int type = CMD,
    ],
 */
typedef struct s_instr
{
	int		type;
	t_vec	arg;
	int		fds[2];
    int     err;
}			t_instr;

typedef struct sigaction	t_sigaction;
extern t_minishell			g_data;

/* ************************************************************************** */

void	msh_exit(int exit_code, char *msg);

/* ************************************************************************** */

#endif
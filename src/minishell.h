/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:52 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/04 13:08:41 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */

# define PROMPT_START           "(o_O)> "
# define SECUNDARY_PROMPT_START "> "

/* ************************************************************************** */

# define ERR_PARSE				"Parsing Error"

/* ************************************************************************** */

# define CMD_INSTR				1
# define CMD_REDIRECT			2
# define CMD_SEPARATOR			3
# define REDIR_IN_FILE			4
# define REDIR_IN_WRITE			5
# define REDIR_OUT_FILE			6
# define REDIR_OUT_CONCA		7

//https://github.com/bminor/bash/blob/
//f3a35a2d601a55f337f8ca02a541f8c033682247/shell.h#L66
# define EX_NOTFOUND            127

# include <stdio.h>
# include <stdlib.h>
# include "vector_lib.h"

# include "msh_debug.h"

/* ************************************************************************** */

typedef struct s_minishell
{
	char	*line_read;
	char	*env_path;
	t_vec	lexed_command;
	t_vec	lexed_instr;
	t_vec	tmp;
	t_vec	env;
	t_vec	env_s;
	t_vec	prompt_start;
	int		last_exit_code;
	int		pipe_buf[2];
	int		code_buf;
	size_t	parsing_index;
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
	int		err;
}			t_instr;

typedef struct sigaction	t_sigaction;
extern t_minishell			g_data;

/* ************************************************************************** */

int	msh_return(int return_value, int exit_code, char *message, const char *fct);
int	msh_exit(unsigned char exit_code, char *message, const char *fct);
/* ************************************************************************** */

#endif
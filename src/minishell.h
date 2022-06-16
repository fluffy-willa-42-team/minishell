/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:52 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/16 13:46:14 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */

# define PROMPT_START           "(o_O)> "
# define SECUNDARY_PROMPT_START "0> "

/* ************************************************************************** */

# include <stdio.h>
# include "vector_lib.h"
# include "libft.h"

/* ************************************************************************** */

typedef struct s_minishell
{
	char	*env_path;
	// Sanitize command.
	t_vec	lexed_command;
	// Lexed commad in struct format.
	t_vec	lexed_instr;
	// Always delete content before use !
	t_vec	tmp;
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
}				t_instr;

typedef struct sigaction	t_sigaction;
extern t_minishell			g_data;

/* ************************************************************************** */

void	msh_exit(int exit_code, char *msg);

/* ************************************************************************** */

#endif
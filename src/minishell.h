/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:52 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/27 09:53:32 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */

# define PROMPT_START "o_O> "

/* ************************************************************************** */

# include "vector_lib.h"
# include "libft.h"

/* ************************************************************************** */

typedef struct s_minishell
{
	char	*env_path;
	t_vec	lexed_comands;
	t_vec	lexed_instr;
}				t_minishell;

typedef struct sigaction	t_sigaction;
extern t_minishell			g_data;

/* ************************************************************************** */

#endif
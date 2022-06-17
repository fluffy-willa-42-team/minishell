/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:21:17 by awillems          #+#    #+#             */
/*   Updated: 2022/06/17 11:04:29 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_LEXER_H
# define MSH_LEXER_H

/* ************************************************************************** */

# include "minishell.h"
# include "vec_utils.h"

/* ************************************************************************** */

typedef struct s_lexer_opt
{
	int		new_instr;
	int		new_arg;
	size_t	nb_instr;
	size_t	index_line;
	long	index_instr;
	int		change_instr;
}	t_lexer_opt;

typedef int	(*t_lexer_param)(char *line, int index, t_lexer_opt *opt);

/* ************************************************************************** */

int		add_char(t_lexer_opt *opt, char *arg);
void	add_arg(t_lexer_opt *opt);
void	new_instr(t_lexer_opt *opt, int type);

int		dflt_char(char *line, int index, t_lexer_opt *opt);
int		bkslh(char *line, int index, t_lexer_opt *opt);
int		sglqot(char *line, int index, t_lexer_opt *opt);
int		dblqot(char *line, int index, t_lexer_opt *opt);
int		varsub(char *line, int index, t_lexer_opt *opt);
int		whtspc(char *line, int index, t_lexer_opt *opt);
int		spec_0_arg(char *line, int index, t_lexer_opt *opt);
int		spec_1_arg(char *line, int index, t_lexer_opt *opt);

/* ************************************************************************** */

#endif
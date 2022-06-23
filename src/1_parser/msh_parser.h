/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:21:17 by awillems          #+#    #+#             */
/*   Updated: 2022/06/20 11:45:45 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_LEXER_H
# define MSH_LEXER_H

/* ************************************************************************** */

# include "minishell.h"
# include "lib_str.h"
# include "lib_is_check.h"
# include "lib_atoi.h"
# include "vec_utils.h"

/* ************************************************************************** */

# define NEW_INSTR		0b0001
# define NEW_ARG		0b0010
# define CHANGE_INSTR	0b0100
# define NEW_CMD		0b1000

typedef struct s_parser_opt
{
	size_t	nb_instr;
	size_t	index_line;
	long	index_instr;
	int		option;
}	t_parser_opt;

typedef int	(*t_parser_param)(char *line, int index, t_parser_opt *opt);

/* ************************************************************************** */

int		add_char(t_parser_opt *opt, char *arg);
void	add_arg(t_parser_opt *opt);
void	new_instr(t_parser_opt *opt, int type);

int		dflt_char(char *line, int index, t_parser_opt *opt);
int		bkslh(char *line, int index, t_parser_opt *opt);
int		sglqot(char *line, int index, t_parser_opt *opt);
int		dblqot(char *line, int index, t_parser_opt *opt);
int		varsub(char *line, int index, t_parser_opt *opt);
int		whtspc(char *line, int index, t_parser_opt *opt);
int		spec_0_arg(char *line, int index, t_parser_opt *opt);
int		spec_1_arg(char *line, int index, t_parser_opt *opt);

/* ************************************************************************** */

#endif
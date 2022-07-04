/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:21:17 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 17:38:16 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_PARSER_H
# define MSH_PARSER_H

/* ************************************************************************** */

# include <stddef.h>
#include <stdio.h>

/* ************************************************************************** */

# define NEW_INSTR		0b1
# define NEW_ARG		0b10
# define CHANGE_INSTR	0b100
# define NEW_CMD		0b1000
# define EMPTY_VAR		0b10000
# define PARSING_ERROR	0b100000
# define ALLOC_FAIL		0b1000000

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
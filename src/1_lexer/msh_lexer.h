/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:21:17 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 11:58:43 by awillems         ###   ########.fr       */
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
}	t_lexer_opt;


/* ************************************************************************** */

int dflt_char(char *line, int index, t_lexer_opt *opt);
int	bkslh(char *line, int index, t_lexer_opt *opt);
int	sglqot(char *line, int index, t_lexer_opt *opt);
int	dblqot(char *line, int index, t_lexer_opt *opt);
int	varsub(char *line, int index, t_lexer_opt *opt);
int	whtspc(char *line, int index, t_lexer_opt *opt);
int	spec_0_arg(char *line, int index, t_lexer_opt *opt);
int	spec_1_arg(char *line, int index, t_lexer_opt *opt);
int	spec_scndry_prompt(char *line, int index, t_lexer_opt *opt);

/* ************************************************************************** */

#endif
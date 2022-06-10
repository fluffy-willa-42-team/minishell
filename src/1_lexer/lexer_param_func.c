/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_param_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:22:55 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 09:36:33 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	new_instr(size_t index, int type, char *arg);
void	add_arg(size_t index, char *arg);

int bkslh(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

int sglqot(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

int dblqot(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

int varsub(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

int whtspc(char *line, int index, t_lexer_opt *opt)
{
	int i;

	i = 0;
	while (line[index + i] && ft_is_whitespace(line[index + i]))
		i++;
	vec_add(get_line(), "\0");
	opt->new_arg = 1;
	return (i);
}

int spec_0_arg(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

int spec_1_arg(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

int spec_scndry_prompt(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

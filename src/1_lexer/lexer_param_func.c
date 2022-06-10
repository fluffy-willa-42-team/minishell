/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_param_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:22:55 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 10:02:13 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_arg(t_lexer_opt *opt, int index);
void	new_instr(t_lexer_opt *opt, int type, int index);

int dflt_char(char *line, int index, t_lexer_opt *opt)
{
	vec_add(get_line(), &line[index]);
	printf("%d %d %d %d\n", opt->new_instr, opt->new_arg, opt->nb_instr, index);
	if (opt->new_instr == 1)
	{
		new_instr(opt, index, 1);
		opt->new_instr = 0;
	}
	else if (opt->new_arg == 1)
	{
		add_arg(opt, index);
		opt->new_arg = 0;
	}
	return (1);
}

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

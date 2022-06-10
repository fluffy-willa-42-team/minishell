/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_param_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:22:55 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 09:45:02 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	new_instr(size_t index, int type, char *arg, t_lexer_opt *opt);
void	add_arg(size_t index, char *arg);

int dflt_char(char *line, int index, t_lexer_opt *opt)
{
	vec_add(get_line(), &line[index]);
	printf("%d %d %d\n", opt->new_instr, opt->new_arg, opt->nb_instr);
	if (opt->new_instr == 1)
	{
		new_instr(opt->nb_instr, 1, vec_get_str(get_line(), index), opt);
		opt->new_instr = 0;
		opt->nb_instr++;
	}
	(void) line;
	(void) index;
	(void) opt;
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

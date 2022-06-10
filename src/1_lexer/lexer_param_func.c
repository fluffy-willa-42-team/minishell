/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_param_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:22:55 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 10:46:00 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_char(t_lexer_opt *opt, char *arg);
void	add_arg(t_lexer_opt *opt);
void	new_instr(t_lexer_opt *opt, int type);

int dflt_char(char *line, int index, t_lexer_opt *opt)
{
	add_char(opt, &line[index]);
	if (opt->new_instr == 1)
	{
		new_instr(opt, 1);
		opt->new_instr = 0;
	}
	else if (opt->new_arg == 1)
	{
		add_arg(opt);
		opt->new_arg = 0;
	}
	return (1);
}

/** / */
int bkslh(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

/** ' */
int sglqot(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

/** " */
int dblqot(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

/** $VAR */
int varsub(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

/**  " " \t \n \v \f \r */
int whtspc(char *line, int index, t_lexer_opt *opt)
{
	int i;

	i = 0;
	while (line[index + i] && ft_is_whitespace(line[index + i]))
		i++;
	if (!opt->new_arg)
		add_char(opt, "\0");
	opt->new_arg = 1;
	return (i);
}

/** | ; */
int spec_0_arg(char *line, int index, t_lexer_opt *opt)
{
	if (!opt->new_arg)
		add_char(opt, "\0");
	add_char(opt, &line[index]);
	new_instr(opt, 2);
	add_char(opt, "\0");
	opt->new_instr = 1;
	opt->new_arg = 1;
	return (1);
}

/** < > >> */
int spec_1_arg(char *line, int index, t_lexer_opt *opt)
{
	int len;	

	len = 1;
	if (!opt->new_arg)
		add_char(opt, "\0");
	add_char(opt, &line[index]);
	new_instr(opt, 2);
	if (line[index + 1] && line[index + 1] == '>')
	{
		add_char(opt, &line[index]);
		len += 1;
	}
	add_char(opt, "\0");
	opt->new_instr = 1;
	opt->new_arg = 1;
	return (len);
}

/** << */
int spec_scndry_prompt(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (2);
}

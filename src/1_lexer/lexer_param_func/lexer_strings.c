/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:26:12 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 12:26:20 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

/** ' */
int sglqot(char *line, int index, t_lexer_opt *opt)
{
	int	i;
	int	is_first;

	if (opt->new_instr == 1)
	{
		new_instr(opt, 1);
		opt->new_instr = 0;
	}
	if (!opt->new_arg)
		add_char(opt, "\0");
	is_first = 1;
	i = 1;
	while (line[index + i] && line[index + i] != '\'')
	{
		add_char(opt, &line[index + i]);
		if (is_first)
		{
			add_arg(opt);
			is_first = 0;
		}
		printf("here %s\n", &line[index + i]);
		i++;
	}
	add_char(opt, "\0");
	opt->new_arg = 1;
	return (i);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:26:41 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 12:26:53 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

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
	if (line[index + 1] && line[index] == '>' && line[index + 1] == '>')
	{
		add_char(opt, &line[index]);
		len += 1;
	}
	add_char(opt, "\0");
	// /!\ arg
	// cat < Makefile -b  ==  cat -b Makefile
	opt->new_arg = 1;
	// opt->new_instr = 1;
	opt->index_instr = opt->nb_instr - 2;
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

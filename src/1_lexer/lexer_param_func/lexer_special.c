/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:26:41 by awillems          #+#    #+#             */
/*   Updated: 2022/06/16 13:46:20 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

/** | ; */
int spec_0_arg(char *line, int index, t_lexer_opt *opt)
{
	if (!opt->new_arg)
		add_char(opt, "\0");
	add_char(opt, &line[index]);
	opt->index_instr = -1;
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
	opt->index_instr = opt->nb_instr;
	if (!opt->new_arg)
		add_char(opt, "\0");
	add_char(opt, &line[index]);
	new_instr(opt, 2);
	if (line[index + 1] && ((line[index] == '>' && line[index + 1] == '>')
			|| (line[index] == '<' && line[index + 1] == '<')))
		len += add_char(opt, &line[index]);
	add_char(opt, "\0");
	opt->new_arg = 1;
	opt->change_instr = 1;
	opt->index_instr = opt->nb_instr - 1;
	return (len);
}

/** << */
int spec_scndry_prompt(char *line, int index, t_lexer_opt *opt)
{
	char *line_read;
	
	spec_1_arg(line, index, opt);
	line_read = readline(SECUNDARY_PROMPT_START);
	while (line_read)
	{
		if (line_read && line_read[0])
		{
			printf("line_read : %s\n", line_read);
		}
		free(line_read);
		line_read = readline(SECUNDARY_PROMPT_START);
	}
	free(line_read);
	return (2);
}

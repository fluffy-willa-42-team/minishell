/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sgl_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:19:07 by awillems          #+#    #+#             */
/*   Updated: 2022/06/16 11:20:14 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_instr_or_arg(t_lexer_opt *opt);

static int	add_sglqot(char *line, int index, t_lexer_opt *opt)
{
	int	i;

	i = 0;
	while (line[index + ++i] && line[index + i] != '\'')
		add_char(opt, &line[index + i]);
	return (i);
}

/** ' */
int sglqot(char *line, int index, t_lexer_opt *opt)
{
	int	i;

	opt->index_line++;
	add_instr_or_arg(opt);
	opt->index_line--;
	i = add_sglqot(line, index, opt);
	if (line[index + i] != '\'')
	{
		printf("/!\\ unclosed single quote\n");//TODO
		return (i);
	}
	return (i + 1);
}
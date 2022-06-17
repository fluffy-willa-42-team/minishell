/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:24:32 by awillems          #+#    #+#             */
/*   Updated: 2022/06/17 09:18:50 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_instr_or_arg(t_lexer_opt *opt);

int	dflt_char(char *line, int index, t_lexer_opt *opt)
{
	add_char(opt, &line[index]);
	add_instr_or_arg(opt);
	return (1);
}

/** / */
int	bkslh(char *line, int index, t_lexer_opt *opt)
{
	dflt_char(line, index + 1, opt);
	if (!line[index + 1])
		return (1);
	return (2);
}

/**  " " \t \n \v \f \r */
int	whtspc(char *line, int index, t_lexer_opt *opt)
{
	int	i;

	i = 0;
	while (line[index + i] && ft_is_whitespace(line[index + i]))
		i++;
	if (!opt->new_arg)
	{
		add_char(opt, "\0");
		opt->new_arg = 1;
	}
	return (i);
}

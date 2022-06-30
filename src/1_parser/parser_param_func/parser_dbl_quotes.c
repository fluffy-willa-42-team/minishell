/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dbl_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:19:03 by awillems          #+#    #+#             */
/*   Updated: 2022/06/30 10:33:31 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_parser.h"

void	add_instr_or_arg(t_parser_opt *opt);
int		add_varsub(char *line, int index, t_parser_opt *opt);

/**
 * @brief Adds the string inside the line buffer with the varsub and / taken
 * care of.
 */
static int	add_dblqot(char *line, int index, t_parser_opt *opt)
{
	int	i;

	i = 0;
	while (line[++i + index] && line[index + i] != '\"')
	{
		if (line[index + i] == '\\' && line[index + i]
			&& line[index + i + 1] != '\\')
		{
			add_char(opt, &line[index + i + 1]);
			if (line[index + i + 1])
				i++;
		}
		else if (line[index + i] == '$')
		{
			i += add_varsub(line, index + i, opt) - 1;
			opt->option = opt->option & ~(EMPTY_VAR);
		}
		else
			add_char(opt, &line[index + i]);
	}
	return (i);
}

/**
 * @brief Will add the string surrounded with double quotes ("str") in the
 * buffer and add the it to a new instruction or argument if needed to.
 * 
 * @param line Line read by Readline
 * @param index Index of the character inside the line read by Readline.
 * @param opt Option of the line.
 * @return Returns the number of character read inside the line read by
 * Readline.
 */
int	dblqot(char *line, int index, t_parser_opt *opt)
{
	int	i;

	opt->index_line++;
	add_instr_or_arg(opt);
	opt->index_line--;
	i = add_dblqot(line, index, opt);
	if (line[index + i] != '\"')
	{
		printf("/!\\ unclosed double quote\n");//TODO
		return (i);
	}
	return (i + 1);
}

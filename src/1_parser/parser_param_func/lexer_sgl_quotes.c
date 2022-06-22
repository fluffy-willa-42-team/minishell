/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sgl_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:19:07 by awillems          #+#    #+#             */
/*   Updated: 2022/06/22 14:02:45 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_parser.h"

void	add_instr_or_arg(t_parser_opt *opt);

/**
 * @brief Adds the string inside the line buffer.
 */
int	add_sglqot(char *line, int index, t_parser_opt *opt)
{
	int	i;

	i = 0;
	while (line[index + ++i] && line[index + i] != '\'')
		add_char(opt, &line[index + i]);
	return (i);
}

/** ' */

/**
 * @brief Will add the string surrounded with single quotes ('str') in the
 * buffer and add the it to a new instruction or argument if needed to.
 * 
 * @param line Line read by Readline
 * @param index Index of the character inside the line read by Readline.
 * @param opt Option of the line.
 * @return Returns the number of character read inside the line read by
 * Readline.
 */
int	sglqot(char *line, int index, t_parser_opt *opt)
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

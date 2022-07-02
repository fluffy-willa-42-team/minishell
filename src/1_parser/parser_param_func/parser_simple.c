/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_simple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:24:32 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 17:39:06 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_parser.h"
#include "lib_is_check.h"

void	add_instr_or_arg(t_parser_opt *opt);

/**
 * @brief Will add the character inside the buffer and add the it to a new
 * instruction or argument if needed to.
 * 
 * @param line Line read by Readline
 * @param index Index of the character inside the line read by Readline.
 * @param opt Option of the line.
 * @return Returns the number of character read inside the line read by
 * Readline.
 */
int	dflt_char(char *line, int index, t_parser_opt *opt)
{
	if (!add_char(opt, &line[index]))
		return (1);
	add_instr_or_arg(opt);
	return (1);
}

/**
 * @brief Will add the character next to the / in question inside the buffer
 * and add the it to a new instruction or argument if needed to.
 * 
 * @param line Line read by Readline
 * @param index Index of the character inside the line read by Readline.
 * @param opt Option of the line.
 * @return Returns the number of character read inside the line read by
 * Readline.
 */
int	bkslh(char *line, int index, t_parser_opt *opt)
{
	dflt_char(line, index + 1, opt);
	if (!line[index + 1])
		return (1);
	return (2);
}

/**
 * @brief Will add \0 inside the buffer in the place of the whitespace character
 * and change the option for creating a argument.
 * 
 * @param line Line read by Readline
 * @param index Index of the character inside the line read by Readline.
 * @param opt Option of the line.
 * @return Returns the number of character read inside the line read by
 * Readline.
 */
int	whtspc(char *line, int index, t_parser_opt *opt)
{
	int	i;

	i = 0;
	while (line[index + i] && ft_is_whitespace(line[index + i]))
		i++;
	if (!(opt->option & NEW_ARG))
	{
		if (!add_char(opt, "\0"))
			return (i);
		opt->option |= NEW_ARG;
	}
	return (i);
}

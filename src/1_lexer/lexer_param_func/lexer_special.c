/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:26:41 by awillems          #+#    #+#             */
/*   Updated: 2022/06/17 14:34:13 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

int	return_type_for_spec(char *elem)
{
	const char	*param[] = {"<<", ">>", "|", ";", "<", ">"};
	const int	instr_type[] = {5, 7, 2, 3, 4, 6};
	int			index;

	index = 0;
	while (index < 2)
	{
		if (ft_strncmp(elem, param[index], 2) == 0)
			return (instr_type[index]);
		index++;
	}
	while (index < 6)
	{
		if (ft_strncmp(elem, param[index], 1) == 0)
			return (instr_type[index]);
		index++;
	}
	return (8);
}

/**
 * @brief Will create a new instruction with no argument. (alias ; and |)
 * 
 * @param line Line read by Readline
 * @param index Index of the character inside the line read by Readline.
 * @param opt Option of the line.
 * @return Returns the number of character read inside the line read by
 * Readline.
 */
int	spec_0_arg(char *line, int index, t_lexer_opt *opt)
{
	if (!opt->new_arg)
		add_char(opt, "\0");
	add_char(opt, &line[index]);
	opt->index_instr = -1;
	new_instr(opt, return_type_for_spec(&line[index]));
	add_char(opt, "\0");
	opt->new_instr = 1;
	opt->new_arg = 1;
	return (1);
}

/**
 * @brief Will create a new instruction with one argument.
 * (alias <<, <, > and >>)
 * 
 * @param line Line read by Readline
 * @param index Index of the character inside the line read by Readline.
 * @param opt Option of the line.
 * @return Returns the number of character read inside the line read by
 * Readline.
 */
int	spec_1_arg(char *line, int index, t_lexer_opt *opt)
{
	int	len;	

	len = 1;
	opt->index_instr = opt->nb_instr;
	if (!opt->new_arg)
		add_char(opt, "\0");
	add_char(opt, &line[index]);
	new_instr(opt, return_type_for_spec(&line[index]));
	if (line[index + 1] && line[index] == line[index + 1])
		len += add_char(opt, &line[index]);
	add_char(opt, "\0");
	opt->new_arg = 1;
	opt->change_instr = 1;
	opt->index_instr = opt->nb_instr - 1;
	return (len);
}

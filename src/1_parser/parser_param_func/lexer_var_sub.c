/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_var_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:26:12 by awillems          #+#    #+#             */
/*   Updated: 2022/06/22 14:02:45 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_parser.h"

void	add_instr_or_arg(t_parser_opt *opt);

/**
 * @brief Gets the length of the current variable.
 */
static int	get_var_len(char *line, int index)
{
	int	len;

	len = 0;
	while (ft_isalpha(line[index + len]) || line[index + len] == '_'
		|| (len != 0 && ft_isdigit(line[index + len])))
		len++;
	return (len);
}

/**
 * @brief Adds the variable inside the line buffer.
 */
int	add_varsub(char *line, int index, t_parser_opt *opt)
{
	const int	len = get_var_len(line, index + 1);
	char		*value;

	if (len == 0)
	{
		if (line[index + 1] && line[index + 1] == '?')
		{
			value = ft_itoa(g_data.last_exit_code);
			if (!value)
				exit(1);//TODO
			vec_fill(get_line(), DEFAULT, value);
			free(value);
			return (2);
		}
		return (add_char(opt, "$"));
	}
	vec_fill(&g_data.tmp, FIXED_LEN, &line[index + 1], len);
	value = getenv(vec_get_str(&g_data.tmp, 0));
	vec_delete(&g_data.tmp);
	if (value)
	{
		vec_fill(get_line(), DEFAULT, value);
		opt->index_line += ft_strlen(value);
	}
	else
		opt->option |= EMPTY_VAR;
	return (len + 1);
}

/**
 * @brief Will add the a Variable or a $ if it is alone add the it to a new
 * instruction or argument if needed to.
 * 
 * @param line Line read by Readline
 * @param index Index of the character inside the line read by Readline.
 * @param opt Option of the line.
 * @return Returns the number of character read inside the line read by
 * Readline.
 */
int	varsub(char *line, int index, t_parser_opt *opt)
{
	int	temp1;
	int	temp2;
	int	len_to_skip;
	
	temp1 = opt->index_line + 1;
	len_to_skip = add_varsub(line, index, opt);
	if (opt->option & EMPTY_VAR)
	{
		opt->option &= ~(EMPTY_VAR);
		return (len_to_skip);
	}
	temp2 = opt->index_line;
	opt->index_line = temp1;
	add_instr_or_arg(opt);
	opt->index_line = temp2;
	return (len_to_skip);
}

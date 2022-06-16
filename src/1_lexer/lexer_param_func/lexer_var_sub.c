/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_var_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:26:12 by awillems          #+#    #+#             */
/*   Updated: 2022/06/16 12:53:40 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_instr_or_arg(t_lexer_opt *opt);

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
int	add_varsub(char *line, int index, t_lexer_opt *opt)
{
	const int	len = get_var_len(line, index + 1);
	char		*value;

	if (len == 0)
		return (add_char(opt, "$"));
	vec_fill(&g_data.tmp, FIXED_LEN, &line[index + 1], len);
	value = getenv(vec_get_str(&g_data.tmp, 0));
	vec_delete(&g_data.tmp);
	if (value)
	{
		vec_fill(get_line(), DEFAULT, value);
		opt->index_line += ft_strlen(value);
	}
	return (len + 1);
}

/** $VAR */
int varsub(char *line, int index, t_lexer_opt *opt)
{
	opt->index_line++;
	add_instr_or_arg(opt);
	opt->index_line--;
	return (add_varsub(line, index, opt));
}

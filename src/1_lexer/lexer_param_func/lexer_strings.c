/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:26:12 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 13:32:18 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

/** ' */
int sglqot(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

/** " */
int dblqot(char *line, int index, t_lexer_opt *opt)
{
	(void) line;
	(void) index;
	(void) opt;
	return (1);
}

static int	get_var_len(char *line, int index)
{
	int	len;
	
	len = 0;
	while (ft_isalpha(line[index + len]) || line[index + len] == '_'
		|| (len != 0 && ft_isdigit(line[index + len])))
		len++;
	return (len);
}

/** $VAR */
int varsub(char *line, int index, t_lexer_opt *opt)
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
		opt->index_line++;
	}
	else
		add_char(opt, "\0");
	if (opt->new_instr == 1)
	{
		new_instr(opt, 1);
		opt->new_instr = 0;
	}
	else
		add_arg(opt);
	if (value)
		opt->index_line += ft_strlen(value) - 1;
	return (len + 1);
}

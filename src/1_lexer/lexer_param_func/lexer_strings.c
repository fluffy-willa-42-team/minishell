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

static void	add_instr_or_arg(t_lexer_opt *opt)
{
	if (opt->new_instr == 1)
	{
		new_instr(opt, 1);
		opt->new_instr = 0;
	}
	else if (opt->new_arg == 1)
		add_arg(opt);
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

/* ************************************************************************** */

/** ' */
int sglqot(char *line, int index, t_lexer_opt *opt)
{
	int	i;

	i = 0;
	opt->index_line++;
	add_instr_or_arg(opt);
	opt->index_line--;
	while (line[index + ++i] && line[index + i] != '\"')
		add_char(opt, &line[index + i]);
	if (line[index + i] != '\"')
	{
		printf("/!\\ unclosed single quote\n");//TODO
		return (i);
	}
	return (i + 1);
}

static int	add_var_to_line(t_lexer_opt *opt, char *line, int index)
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

/* ************************************************************************** */

/** " */
int dblqot(char *line, int index, t_lexer_opt *opt)
{
	int	i;

	i = 0;
	opt->index_line++;
	add_instr_or_arg(opt);
	opt->index_line--;
	while (line[++i + index] && line[index + i] != '\"')
	{
		if (line[index + i] == '\\' && line[index + i] && line[index + i + 1] != '\\')
		{
			add_char(opt, &line[index + i + 1]);
			if (line[index + i + 1])
				i++;
		}
		else if (line[index + i] == '$')
			i += add_var_to_line(opt, line, index + i) - 1;
		else
			add_char(opt, &line[index + i]);
	}
	if (line[index + i] != '\"')
	{
		printf("/!\\ unclosed double quote\n");//TODO
		return (i);
	}
	return (i + 1);
}

/* ************************************************************************** */

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
	add_instr_or_arg(opt);
	if (value)
		opt->index_line += ft_strlen(value) - 1;
	return (len + 1);
}

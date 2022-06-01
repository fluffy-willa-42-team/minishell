/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_param_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:25:32 by awillems          #+#    #+#             */
/*   Updated: 2022/06/01 09:16:02 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>   /* getenv */
#include "vec_utils.h"
#include <stdio.h>

/**
 * @brief If the char at the index in the line is a white space that is not
 * followed by another, it will replace it with a unit separator. On the
 * contrary it will be skipped.
 */
int whtspc(t_vec *vec, char *line, int index)
{
	if (line[index + 1] != 0 && !ft_is_whitespace(line[index + 1]))
		vec_add(vec, "\31");
	return (index + 1);
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

/**
 * @brief When a `$` is occur, will check if the next character is `alphanum`,
 *        make `getenv` and push the variable content inside line buffer.   If
 *        the character after `$` is `!alphanum` will push `$` in line buffer.
 * 
 * 
 */
int varsub(t_vec *vec, char *line, int index)
{
	int		len;
	char	*env_str;

	index++;
	if (!(ft_isalpha(line[index]) || line[index] == '_'))
	{
		vec_add(vec, "$");
		return (index);
	}
	len = get_var_len(line, index);
	vec_delete(&g_data.tmp);
	vec_fill(&g_data.tmp, FIXED_LEN, &line[index], len);
	env_str = getenv(g_data.tmp.buffer);
	if (env_str)
		vec_fill(vec, DEFAULT, env_str);
	return (index + len);
}

/**
 * @brief If the char at the index in the line is a \, it will be either skipped
 * or save another \ from being skipped.
 */
int bkslh(t_vec *vec, char *line, int index)
{
	if (line[index + 1] && line[index + 1] == '\\'){
		vec_add(vec, "\\");
		return (index + 2);
	}
	return (index + 1);
}

/**
 * @brief 
 */
int sglqot(t_vec *vec, char *line, int index)
{
	index++;
	while (line[index] && line[index] != '\'')
	{
		vec_add(vec, &line[index]);
		index++;
	}
	if (!line[index])
		return (index);
	return (index + 1);
}

/**
 * @brief 
 */
int dblqot(t_vec *vec, char *line, int index)
{
	const char *to_find = "$\\";
	static int	(*func_link[2])() = {varsub, bkslh};
	char		*ptr;

	index++;
	while (line[index] && line[index] != '\"')
	{
		ptr = ft_strrchr(to_find, line[index]);
		if (ptr)
			index = func_link[ptr - to_find](vec, line, index);
		else
		{
			vec_add(vec, &line[index]);
			index++;
		}
	}
	if (!line[index])
		return (index);
	return (index + 1);
}

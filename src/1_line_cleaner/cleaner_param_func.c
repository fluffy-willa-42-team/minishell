/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_param_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:25:32 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 13:02:45 by awillems         ###   ########.fr       */
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
	(void) vec;
	(void) line;
	(void) index;
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
 */
int varsub(t_vec *vec, char *line, int index)
{
	const int	len = get_var_len(line, index + 1);
	char		*env_str;

	if (len == 0)
	{
		vec_add(vec, "$");
		return (index + 1);
	}
	vec_delete(&g_data.tmp);
	vec_fill(&g_data.tmp, FIXED_LEN, &line[index + 1], len);
	env_str = getenv(vec_get_str(&g_data.tmp, 0));
	if (env_str)
		vec_fill(vec, DEFAULT, env_str);
	return (index + 1 + len);
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

/**
 * @brief Will split string seperate by `<>|`
 */
int redir(t_vec *vec, char *line, int index)
{
	int		i;

	i = 0;
	while (line[index + i] && line[index + i] == line[index])
	{
		vec_add(vec, &line[index + i]);
		i++;
	}
	vec_add(vec, "\0");
	return (index + i);
}
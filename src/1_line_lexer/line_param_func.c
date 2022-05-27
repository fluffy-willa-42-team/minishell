/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_param_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:25:32 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 16:45:08 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>   /* getenv */
#include "vec_utils.h"
#include <stdio.h>

/**
 * @brief //TODO
 */
int whtspc(t_vec *vec, char *line, int index)
{
	if (line[index + 1] != 0 && !ft_is_whitespace(line[index + 1]))
		vec_fill(vec, FIXED_LEN, " ", 1);
	return (index + 1);
}

/**
 * @brief When a `$` is occur, will check if the next character is `alphanum`,
 *        make `getenv` and push the variable content inside line buffer.   If
 *        the character after `$` is `!alphanum` will push `$` in line buffer.
 */
int varsub(t_vec *vec, char *line, int index)
{
	int		len;
	char	*env_str;

	len = 0;
	// Skip `$`
	index++;
	// Check if the next char is alphanum
	if (!ft_isalnum(line[index]))
	{
		// If not, push `$` and return the index of the char after `$`.
		vec_fill(vec, FIXED_LEN, "$", 1);
		return (index);
	}
	// strlen of the var name
	while (ft_isalnum(line[index + len]))
		len++;
	// Put the var name in tmp buffer
	vec_delete_content(&g_data.tmp);
	vec_fill(&g_data.tmp, FIXED_LEN, &line[index], len);
	// Find the env var with the tmp buffer
	env_str = getenv(g_data.tmp.buffer);
	// If var find push the content in line buffer
	if (env_str)
		vec_fill(vec, DEFAULT, env_str);
	return (index + len);
}

/**
 * @brief //TODO
 */
int bkslh(t_vec *vec, char *line, int index)
{
	if (line[index + 1] && line[index + 1] == '\\'){
		vec_fill(vec, FIXED_LEN, "\\", 1);
		return (index + 2);
	}
	return (index + 1);
}

/**
 * @brief 
 */
int sglqot(t_vec *vec, char *line, int index)
{
	vec_fill(vec, FIXED_LEN, '\'', 1);
	index++;
	while (line[index] && line[index] != '\'')
	{
		vec_fill(vec, FIXED_LEN, &line[index], 1);
		index++;
	}
	if (!line[index])
		return (index);
	vec_fill(vec, FIXED_LEN, '\'', 1);
	return (index + 1);
}

/**
 * @brief 
 */
int dblqot(t_vec *vec, char *line, int index)
{
	vec_fill(vec, FIXED_LEN, '\'', 1);
	index++;
	while (line[index] && line[index] != '\"')
	{
		vec_fill(vec, FIXED_LEN, &line[index], 1);
		index++;
	}
	if (!line[index])
		return (index);
	vec_fill(vec, FIXED_LEN, '\'', 1);
	return (index + 1);
}
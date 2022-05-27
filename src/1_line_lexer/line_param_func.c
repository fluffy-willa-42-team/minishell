/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_param_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:25:32 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 14:40:50 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>   /* getenv */
#include "vec_utils.h"
#include <stdio.h>

/**
 * @brief 
 */
int whtspc(t_vec *vec, char *line, int index)
{
	if (line[index + 1] != 0 && !ft_is_whitespace(line[index + 1]))
		vec_fill(vec, FIXED_LEN, " ", 1);
	return (index + 1);
}

/**
 * @brief 
 */
int varsub(t_vec *vec, char *line, int index)
{
	int	len;

	(void) line;
	(void) vec;
	len = 0;
	index++;
	while (ft_isalnum(line[index]))
		len++;
	if (ft_strchr(" \t\n\v\f\r", line[index]))
		return (index+1);
	return (index+1);
}

/**
 * @brief 
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
	(void) line;
	(void) vec;
	return (index + 1);
}

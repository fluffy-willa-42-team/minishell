/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expend_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:15:00 by awillems          #+#    #+#             */
/*   Updated: 2022/05/26 11:29:45 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include "msh_debug.h"
#include "msh_struct.h"

#include "vector_lib.h"
#include "libft.h"


void	get_var(const char *env)
{
	char *env_str;

	env_str = getenv(env);
	if (!env_str || MSH_DEBUG)
	{
		printf("WARN: getenv dont find the var\n");
	}
	free(env_str);
}

/**
 * @brief 
 * 
 */
void	expend_var(t_vec *line)
{
	int len = ft_strlen(line->buffer);
	int is_in_quotes = 0;
	int i = 0;
	while (i < len)
	{
		if (((char *) line->buffer)[i] == '\'')
			is_in_quotes = !is_in_quotes;
		else if (((char *) line->buffer)[i] == '$' && !is_in_quotes)
		{
			if (i < len - 1 && ((char *) line->buffer)[i + 1] == '{')
			{
				printf("{\n");
				//wait for closing bracket
			}
			else
			{
				printf("\\t\n");
				//wait for whitespace ?
			}
			printf("var\n");
		}
		i++;
	}
}

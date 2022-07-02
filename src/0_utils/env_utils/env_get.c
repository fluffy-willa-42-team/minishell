/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:00:54 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 11:01:31 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

/**
 * [LOCAL] return the len of env_s.
 */
static size_t	c_len(void)
{
	return (g_data.env_s.len);
}

/**
 * Will hash name and try to find in the hash table.
 * WARN : If name = `""` the hash will be 5381
 */
t_env	*env_get(char *name)
{
	unsigned long	hash;
	size_t			i;

	i = 0;
	while (name[i])
		i++;
	hash = djb2_hash(name, i);
	printf("[INFO] env_get: check for [%s][%lu] ", name, hash);//TODO REMOVE DEBUG
	i = -1;
	while (++i < c_len())
	{
		if (vec_get_t_env_raw(i)->token == hash)
		{
			printf(" FOUND :D\n");//TODO REMOVE DEBUG
			return (vec_get_t_env_raw(i));
		}
	}
	printf("not FOUND :(\n");//TODO REMOVE DEBUG
	return (NULL);
}

char	*env_get_content(char *name)
{
	t_env	*tmp;

	tmp = env_get(name);
	if (tmp)
		return ((char *) tmp->content.buffer + tmp->env_len + 1);
	return (NULL);
}

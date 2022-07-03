/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:00:54 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 15:59:54 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"
#include "vec_utils.h"

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
	if (DEBUG_PRINT)
		printf("[INFO] env_get: check for [%s][%lu]\n", name, hash);
	i = -1;
	while (++i < c_len())
	{
		if (vec_get_t_env_raw(i)->token == hash)
		{
			return (vec_get_t_env_raw(i));
		}
	}
	return (NULL);
}

char	*env_get_content(char *name)
{
	t_env	*tmp;

	if (DEBUG_PRINT)
		printf("[INFO] env_get_content: try to find [%s]\n", name);
	tmp = env_get(name);
	if (tmp)
		return ((char *) tmp->content.buffer + tmp->env_len + 1);
	if (DEBUG_PRINT)
		printf("[INFO] env_get_content: [%s] not find, return NULL\n", name);
	return (NULL);
}

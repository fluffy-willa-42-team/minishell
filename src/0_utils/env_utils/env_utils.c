/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:53:58 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/02 10:55:59 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "env_utils.h"
#include "lib_str.h"

/**
 * [LOCAL] return the len of env_s.
 * WARN!! cast size_t to int
 */
static int	c_len(void)
{
	return ((int)g_data.env_s.len);
}

/**
 * @brief Will destroy the env vector and pop.
 *        WARN! If the content dont exist will segfault !! //TODO check 
 */
t_vec	*env_pop(t_vec *vec, int index)
{
	vec_destroy(&vec_get_t_env(index)->content);
	return (vec_pop(vec, index));
}

/**
 * @brief Will erase all content and set `token` and `env_len` to `0`.
 *        WARN! If the content dont exist will segfault !! //TODO check 
 */
void	env_unset(t_env *env)
{
	vec_delete(&env->content);
	env->env_len = 0;
	env->token = 0;
}

/**
 * Will hash name and try to find in the hash table.
 * WARN : If name = `""` the hash will be 5381
 */
t_env	*env_get(char *name)
{
	unsigned long	hash;
	int				i;

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

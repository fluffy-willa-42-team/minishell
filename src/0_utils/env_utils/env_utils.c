/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:53:58 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/01 17:30:56 by mahadad          ###   ########.fr       */
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
	printf("[INFO] env_get: check for [%s][%lu]\n", name, hash);//TODO REMOVE DEBUG
	i = 0;
	while (i < c_len() && vec_get_t_env_raw(i)->token != hash)
	{
		printf("[INFO] env_get: cmp [%s][%s]\n", name, vec_get_t_env_str(i));//TODO REMOVE DEBUG
		i++;
	}
	#error TODO CHECK why this if return NULL.
	if (i == c_len())
	{
		printf("[INFO] env_get: return NULL\n");//TODO REMOVE DEBUG
		return (NULL);
	}
	printf("[INFO] env_get: FOUND!\n");//TODO REMOVE DEBUG
	return (vec_get_t_env_raw(i));
}

char	*env_get_content(char *name)
{
	t_env	*tmp;

	tmp = env_get(name);
	if (tmp)
		return ((char *) tmp->content.buffer + tmp->env_len + 1);
	return (NULL);
}

//TODO REMOVE DEBUG STUFF
//TODO TO THE NORM
//TODO REMOVE PRINT LIMIT
void	print_env(void)
{
	size_t i = -1;
	char	*tmp;

	setbuf(stdout, NULL);//TODO remove
	printf("ENV TAB SIZE[%lu]\n", g_data.env.len);
	while (++i < g_data.env.len)
	{
		printf("[%lu] ", i);//TODO remove
		tmp = ((char **)g_data.env.buffer)[i];
		size_t len = ft_strlen(tmp);
		if (len > 32)
		{
			write(1, tmp, 60);
			write(1, "...\n", 5);
			continue;
		}
		write(1, tmp, len);
		write(1, "\n", 2);
	}
}
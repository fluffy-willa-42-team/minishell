/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:53:14 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/30 11:56:01 by mahadad          ###   ########.fr       */
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
 * [LOCAL]
 * 
 */
static t_env	*set(t_env *env, char *name, char *value)
{
	printf("EDIT %s\n", name);
	vec_delete(&env->content);
	env->env_len = ft_strlen(name);
	env->token = djb2_hash(name, env->env_len);
	vec_fill(&env->content, MULTI, 3, name, "=", value);
	return (env);
}

/**
 * [LOCAL]
 * Try to find a free space and set it. If no free space find will create a new.
 */
static t_env	*set_new(char *name, char *value)
{
	int		i;

	i = 0;
	printf("NOT FOUD %s\n", name);
	while (i < c_len() && vec_get_t_env(i)->token != 0UL)
		i++;
	if (i == c_len())
	{
		printf("NOT FOUD FREE SPACE %s\n", name);
		return (vec_add_new_env(name, value));
	}
	printf("FOUD SPACE %s\n", name);
	return (set(vec_get_t_env(i), name, value));
}

/**
 *  Will hash the `name` and concatenate `${name}=${value}`
 *  Same as :
 *        int setenv(const char *name, const char *value, int overwrite);
 * 
 *        The setenv() function adds the variable name to the environment
 *        with the value value, if name does not already exist.  If name
 *        does exist in the environment, then its value is changed to value
 *        if overwrite is nonzero; if overwrite is zero, then the value of
 *        name is not changed (and setenv() returns a success status).
 * 
 */
t_env	*env_set(char *name, char *value, int overwrite)
{
	t_env	*env;

	env = env_get(name);
	if (!env)
		return (set_new(name, value));
	if (overwrite)
		return (set(env, name, value));
	return (NULL);
}

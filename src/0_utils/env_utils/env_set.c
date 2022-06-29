/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:53:14 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/29 16:07:36 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "env_utils.h"
#include "lib_str.h"

/**
 * [LOCAL] return the content_len of env_s.
 * WARN!! cast size_t to int
 */
static int	c_len(void)
{
	return ((int)g_data.env_s.content_len);
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
 * RETURN VALUE
 *        setenv() and unsetenv() functions return zero on success, or -1
 *        on error, with errno set to indicate the error.
 * ERRORS
 *        EINVAL name is NULL, points to a string of length 0, or contains
 *               an '=' character.
 *        ENOMEM Insufficient memory to add a new variable to the
 *               environment.
 * 
 */
t_env	*env_set(char *name, char *value, int overwrite)
{
	t_env	*env;
	int		i;

	i = 0;
	env = env_get(name);
	if (!env)
	{
		printf("NOT FOUD %s\n", name);
		while (i < c_len() && vec_get_t_env(i)->token != 0UL)
			i++;
		if (i == c_len())
		{
		printf("NOT FOUD FREE SPACE %s\n", name);
			vec_add_new_env(name, value);
			return (env);
		}
		env = vec_get_t_env(i);
		printf("FOUD SPACE %s\n", name);
		overwrite = 1;
	}
	if (overwrite)
	{
		printf("EDIT %s\n", name);
		vec_delete(&env->content);
		env->env_len = ft_strlen(name);
		env->token = djb2_hash(name, env->env_len);
		vec_fill(&env->content, MULTI, 3, name, "=", value);
	}
	return (NULL);
}

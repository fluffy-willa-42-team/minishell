/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add_new_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:54:35 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/05 11:39:12 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "lib_str.h"
#include "minishell.h"
#include "msh_debug.h"

/**
 * Add new t_env structure. If alloc fail will call the exit function.
 * 
 * WARN if there a `=` in the `name` will return error.
 * 
 * EXEMPLE
 *   new("TEST", "UwU Be Gentle");
 *   t_env -> {
 *              token:   6384537573UL,
 *              env_len: 4,
 *              t_vec { buff->"TEST=UwU Be Gentle" },
 *            }
 */
t_env	*vec_add_new_env(char *name, char *content)
{
	t_env	new_env;
	t_vec	*tmp;

	if (!name || ft_strchr(name, '='))
		return (NULL);
	new_env.content = vec_init(sizeof(char));
	new_env.content.exit_func = vec_exit_func;
	if (!vec_fill(&new_env.content, MULTI, 3, name, "=", content))
		return (NULL);
	new_env.env_len = 0;
	while (name[new_env.env_len] && name[new_env.env_len] != '=')
		new_env.env_len++;
	new_env.token = djb2_hash(name, new_env.env_len);
	tmp = vec_add(&g_data.env_s, &new_env);
	if (!tmp)
		return (NULL);
	return ((t_env *)&tmp->buffer);
}

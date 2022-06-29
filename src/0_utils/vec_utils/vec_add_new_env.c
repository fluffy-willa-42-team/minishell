/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add_new_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:54:35 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/29 16:07:50 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "lib_str.h"
#include "minishell.h"

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
void	vec_add_new_env(char *name, char *content)
{
	t_env	new_env;

	if (!name || ft_strchr(name, '='))
	{
		printf ("vec_add_new_env NULL name OR `=`find in name\n");
		exit(1);//TODO
	}
	new_env.content = vec_init(sizeof(char));
	if (!vec_fill(&new_env.content, MULTI, 3, name, "=", content))
	{
		printf("vec_add_new_env fail to write new env");
		exit (1);//TODO
	}
	new_env.env_len = 0;
	while (name[new_env.env_len] && name[new_env.env_len] != '=')
		new_env.env_len++;
	new_env.token = djb2_hash(name, new_env.env_len);
	if (!vec_add(&g_data.env_s, &new_env))
	{
		printf("vec_add_new_env fail to add new env");
		exit (1);//TODO
	}
}
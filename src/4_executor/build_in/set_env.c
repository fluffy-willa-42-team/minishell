/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:51:25 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/30 17:00:20 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "env_utils.h"

t_vec	*env(char **env)
{
	size_t	len;

	if (!env)
		return (NULL);
	env++;
	len = 0;
	while (env[0][len] && env[0][len] != '=')
		len++;
	vec_delete(&g_data.tmp);
	vec_fill(&g_data.tmp, FIXED_LEN, len, *env);
	while (*env)
	{
		printf("env set [%s]\n", *env);
		env_set((char *)g_data.tmp.buffer, *env, 1);//TODO ENV mettre seulement le nom de la variable.
		updt_env();
		print_env();
		env++;
	}
	return NULL;
}
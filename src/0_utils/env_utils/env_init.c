/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:38 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/03 14:33:41 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "env_utils.h"
#include "lib_str.h"
#include "msh_debug.h"
#include <errno.h>
#include <string.h>

/**
 * [LOCAL]
 * Convert unix env structure to t_env structure.
 * First fill the vec with `str`, find the var name length and hash it.
 * 
 * EXEMPLE
 *    unix -> TEST=UwU Be Gentle
 *   t_env -> {
 *              token:   6384537573UL,
 *              env_len: 4,
 *              t_vec { buff->"TEST=UwU Be Gentle" },
 *            }
 */
static int	sysenv_to_t_env(char *str)
{
	t_env	new_env;

	if (!str)
		return (msh_return(0, 1, "sysenv_to_t_env NULL str\n", __FUNCTION__));
	new_env.content = vec_init(sizeof(char));
	if (!vec_fill(&new_env.content, DEFAULT, str))
		return (msh_return(errno, errno, strerror(errno), __FUNCTION__));
	new_env.env_len = 0;
	while (str[new_env.env_len] && str[new_env.env_len] != '=')
		new_env.env_len++;
	new_env.token = djb2_hash(str, new_env.env_len);
	if (!vec_add(&g_data.env_s, &new_env))
		return (msh_return(errno, errno, strerror(errno), __FUNCTION__));
	return (0);
}

t_vec	*updt_env(void)
{
	size_t	i;

	vec_delete(&g_data.env);
	i = -1;
	while (++i < g_data.env_s.len)
	{
		if (!vec_get_t_env_raw(i)->token)
			continue ;
		if (!vec_add(&g_data.env, &vec_get_t_env_raw(i)->content.buffer))
		{
			print_debug("[ERROR] updt_env: vec_add: return NULL\n");
			msh_return(errno, errno, strerror(errno), __FUNCTION__);
		}
	}
	return (&g_data.env);
}

void	init_env(char **env)
{
	int	index;
	int	res;

	index = -1;
	while (env[++index])
	{
		res = sysenv_to_t_env(env[index]);
		if (res != 0)
			exit(res);
	}
	print_debug_sep("T_ENV INIT");
	updt_env();
	if (DEBUG_PRINT)
		print_env("", "=", "");
	print_debug_sep("T_ENV INIT END");
}

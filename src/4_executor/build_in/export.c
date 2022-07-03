/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:51:25 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/03 10:19:51 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "env_utils.h"
#include "minishell.h"
#include "lib_is_check.h"
#include "msh_debug.h"

#include <errno.h>
#include <string.h>
#include <stdio.h>

static int	new_env(char *arg)
{
	int	len;

	len = 0;
	if (!ft_isalpha(arg[len]))
		return (0);
	while (arg[len] && (ft_isalnum(arg[len]) || arg[len] == '_'))
		len++;
	if (arg[len] != '=')
		return ((int []){0, 1}
					[!arg[len] || !(ft_isalnum(arg[len]) || arg[len] == '_')]);
	vec_delete(&g_data.tmp);
	if (!vec_fill(&g_data.tmp, FIXED_LEN, arg, len))
		msh_exit(errno, errno, strerror(errno), __FUNCTION__);
	len++;
	if (!env_set((char *)g_data.tmp.buffer, &arg[len], 1))
		msh_exit(errno, errno, strerror(errno), __FUNCTION__);
	vec_delete(&g_data.tmp);
	if (!updt_env())
		msh_exit(errno, errno, strerror(errno), __FUNCTION__);
	return (1);
}

/**
 * [LOCAL] Will add all env to g_data.env_s.
 */
static int	env_manager(char **arg)
{
	while (*arg)
	{
		if (DEBUG_PRINT)
			printf("[INFO] ENV SET:[%s]\n", *arg);
		if (!new_env(*arg))
			printf("minishell: export: `%s`: not a valid identifier\n", *arg);
		arg++;
	}
	return (1);
}

/**
 * ^[aA][aA0-9]
 */
int	export(char **arg)
{
	if (!arg || !*arg)
		return (0);
	arg++;
	if (!*arg)
	{
		print_env("declare -x ", "=\"", "\"");
		return (1);
	}
	env_manager(arg);
	return (1);
}

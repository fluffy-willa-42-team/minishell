/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:51:25 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/05 10:23:50 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "env_utils.h"
#include "minishell.h"
#include "lib_is_check.h"
#include "msh_debug.h"
#include "lib_put_fd.h"

#include <errno.h>
#include <string.h>
#include <stdio.h>

static int	new_env(char *arg)
{
	int	len;

	len = 0;
	if (!ft_isalpha(arg[len]) && arg[len] != '_')
		return (0);
	while (arg[len] && (ft_isalnum(arg[len]) || arg[len] == '_'))
		len++;
	if (arg[len] != '=')
		return ((int []){0, 1}
					[!arg[len]]);
	vec_delete(&g_data.tmp);
	if (!vec_fill(&g_data.tmp, FIXED_LEN, arg, len))
		msh_return(errno, errno, strerror(errno), __FUNCTION__);
	len++;
	if (!env_set((char *)g_data.tmp.buffer, &arg[len], 1))
		msh_return(errno, errno, strerror(errno), __FUNCTION__);
	vec_delete(&g_data.tmp);
	updt_env();
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
		{
			ft_putstr_fd("minishell: export: `", STDERR_FILENO);
			ft_putstr_fd(*arg, STDERR_FILENO);
			ft_putstr_fd("`: not a valid identifier\n", STDERR_FILENO);
			msh_return(1, 1, NULL, __FUNCTION__);
		}
		arg++;
	}
	return (1);
}

/**
 * ^[aA][aA0-9]
 */
void	msh_export(char **arg)
{
	if (!arg || !*arg)
		return ;
	arg++;
	if (!*arg)
	{
		print_env("declare -x ", "=\"", "\"");
		return ;
	}
	env_manager(arg);
	return ;
}

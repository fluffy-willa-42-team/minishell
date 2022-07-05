/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:06:29 by awillems          #+#    #+#             */
/*   Updated: 2022/07/05 10:23:30 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "msh_debug.h"
#include "lib_is_check.h"
#include "vec_utils.h"
#include "env_utils.h"
#include "lib_put_fd.h"

static int	new_env(char *arg)
{
	int	len;

	len = 0;
	if (!ft_isalpha(arg[len]) && arg[len] != '_')
		return (0);
	while (arg[len] && (ft_isalnum(arg[len]) || arg[len] == '_'))
		len++;
	if (arg[len])
		return (0);
	env_unset(env_get(arg));
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
			printf("[INFO] env_mamager :[%s]\n", *arg);
		if (!new_env(*arg))
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(*arg, STDERR_FILENO);
			ft_putstr_fd("`: not a valid identifier\n", STDERR_FILENO);
			msh_return(1, 1, NULL, __FUNCTION__);
		}
		arg++;
	}
	return (1);
}

void	msh_unset(char **args)
{
	g_data.last_exit_code = 0;
	if (!*args)
		return ;
	args++;
	env_manager(args);
}

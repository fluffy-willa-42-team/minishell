/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:06:29 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 10:19:56 by mahadad          ###   ########.fr       */
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

static int	new_env(char *arg)
{
	int	len;

	len = 0;
	if (!ft_isalpha(arg[len]))
		return (0);
	while (arg[len] && (ft_isalnum(arg[len]) || arg[len] == '_'))
		len++;
	if (arg[len] == '=')
		return (0);
	env_unset(env_get(arg));
	return (1);
}

/**
 * [LOCAL] Will add all env to g_data.env_s.
 */
static int	env_manager(char **arg)
{
	int			i;

	i = 0;
	g_data.last_exit_code = 0;
	while (*arg)
	{
		if (DEBUG_PRINT)
			printf("[INFO] env_mamager :[%s]\n", *arg);
		if (!new_env(*arg))
			printf("minishell: unset: `%s`: not a valid identifier\n", *arg);
		arg++;
	}
	return (1);
}

int	msh_unset(char **args)
{
	if (!*args)
		return (0);
	args++;
	env_manager(args);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:51:25 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/01 17:02:40 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "env_utils.h"
#include "minishell.h"
#include "lib_is_check.h"
#include "msh_debug.h"

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
	{
		print_debug("[ERROR] env_manager: new_env: vec_fill: return NULL\n");
		exit(1);//TODO exit handler for fail memory
	}
	vec_print(&g_data.tmp);//TODO REMOVE
	len++;
	if (!env_set((char *)g_data.tmp.buffer, &arg[len], 1))
	{
		print_debug("[ERROR] env_manager: new_env: env_set: return NULL\n");
		exit(1);//TODO exit handler for fail memory
	}
	if (!updt_env())
	{
		print_debug("[ERROR] env_manager: new_env: updt_env: return NULL\n");
		exit(1);//TODO update env tab fail
	}
	print_env_s();//TODO REMOVE DEBUG
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
		printf("ENV SET:[%s]\n", *arg);
		if (!new_env(*arg))
		{
			printf("minishell: export: `%s`: not a valid identifier\n", *arg);//TODO CHECK FOR THE FD
			g_data.last_exit_code = 1;
		}
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
		print_env();//TODO add stuff before
		return (1);
	}
	if (!env_manager(arg))
	{
		printf("ERROR!!! env_manager\n");
		exit(1);//TODO malloc fail
	}
	return (1);
}

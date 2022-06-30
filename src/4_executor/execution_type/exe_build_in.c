/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_build_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:42:12 by awillems          #+#    #+#             */
/*   Updated: 2022/06/30 16:29:42 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_str.h"
#include "vec_utils.h"
#include "env_utils.h"
#include "build_in.h"

int	exe_build_in(char *cmd, char **args, char **envp)
{
	const char	*buildins[7] = {
		"cd", "pwd", "echo", "export", "unset", "env", "exit"
	};
	const t_build_in	f[7] = {
		dummy, dummy, dummy, dummy, dummy, env, dummy
	};
	int			i;

	i = 0;
	(void) args;
	(void) envp;
	while (i < 7)
	{
		if (ft_strlen(cmd) == ft_strlen(buildins[i])
			&& ft_strcmp(cmd, buildins[i]) == 0)
		{
			printf("[BUILDIN](%d) => %s\n", i, cmd);
			f[i](args);
			return (1);
		}
		i++;
	}
	return (0);
}

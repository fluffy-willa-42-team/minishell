/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_build_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:42:12 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 18:38:24 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_str.h"
#include "vec_utils.h"
#include "env_utils.h"
#include "build_in.h"

int	exe_build_in(char *cmd, char **args, char **envp)
{
	int					i;
	const char			*buildins[] = {
		"cd", "pwd", "echo",
		"export", "unset", "env",
		"exit",
		"e",//WIP TODO REMOVE used as shortcut for fast debug
		"dmsh"
	};
	const t_build_in	f[] = {
		msh_cd, msh_pwd, msh_echo,
		export, msh_unset, env,
		msh_exit_cmd,
		export,//WIP TODO REMOVE used as shortcut for fast debug
		dmsh
	};

	i = -1;
	(void) envp;
	while (++i < 9)
	{
		if (ft_strlen(cmd) == ft_strlen(buildins[i])
			&& ft_strcmp(cmd, buildins[i]) == 0)
		{
			printf("[BUILDIN](%d) => %s\n", i, cmd);
			f[i](args);
			return (1);
		}
	}
	return (0);
}

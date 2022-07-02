/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_build_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:42:12 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 11:16:23 by awillems         ###   ########.fr       */
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
	const char			*buildins[7] = {
		"cd", "pwd", "echo", "export", "unset", "env", "exit"
	};
	const t_build_in	f[7] = {
		msh_cd, msh_pwd, msh_echo, export, msh_unset, env, msh_exit
	};

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

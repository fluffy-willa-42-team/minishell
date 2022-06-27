/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_build_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:42:12 by awillems          #+#    #+#             */
/*   Updated: 2022/06/27 12:54:28 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_str.h"

int	exe_build_in(char *cmd, char **args, char **envp)
{
	const char *buildins[7] = {
		"cd", "pwd", "echo", "export", "unset", "env", "exit"
	};
	
	(void) args;
	(void) envp;
	if (DEBUG_PRINT)
		printf("BUILD IN\n");
	for (int i = 0; i < 7; i++)
	{
		if (ft_strlen(cmd) == ft_strlen(buildins[i])
				&& ft_strcmp(cmd, buildins[i]) == 0)
		{
			printf("[BUILDIN] => %s\n", cmd);
			return (1);
		}
	}
	return (0);
}
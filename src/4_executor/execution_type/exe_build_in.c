/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_build_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:42:12 by awillems          #+#    #+#             */
/*   Updated: 2022/06/30 10:43:46 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_str.h"

int	exe_build_in(char *cmd, char **args, char **envp)
{
	const char	*buildins[7] = {
		"cd", "pwd", "echo", "export", "unset", "env", "exit"
	};
	int			i;

	(void) args;
	(void) envp;
	while (i < 7)
	{
		if (ft_strlen(cmd) == ft_strlen(buildins[i])
			&& ft_strcmp(cmd, buildins[i]) == 0)
		{
			printf("[BUILDIN] => %s\n", cmd);
			return (1);
		}
		i++;
	}
	return (0);
}

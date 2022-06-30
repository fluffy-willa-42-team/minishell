/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:33:46 by awillems          #+#    #+#             */
/*   Updated: 2022/06/30 12:36:08 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
#include <errno.h>

void	exe_file(char *cmd, char **args, char **envp)
{
	if (access(cmd, X_OK) == -1)
	{
		fprintf(stderr, "%s: %s\n", g_data.cmd, strerror(errno));
		exit(EX_NOTFOUND);
	}
	execve(cmd, args, envp);
}

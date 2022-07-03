/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:33:46 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 14:39:12 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
#include <errno.h>

void	exe_file(char *cmd, char **args, char **envp)
{
	if (access(cmd, X_OK) == -1)
	{
		fprintf(stderr, "%s: %s\n", g_data.line_read, strerror(errno));
		exit(EX_NOTFOUND);
	}
	execve(cmd, args, envp);
}

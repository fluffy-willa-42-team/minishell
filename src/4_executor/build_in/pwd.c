/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:06:29 by awillems          #+#    #+#             */
/*   Updated: 2022/07/05 11:43:19 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"
#include <stdio.h>
#include "minishell.h"
#include <errno.h>
#include <string.h>

void	msh_pwd(char **args)
{
	char	*new_dir;

	(void) args;
	if (!g_data.tmp.alloc_len)
		if (!vec_resize(&g_data.tmp))
			msh_exit(errno, strerror(errno), __FUNCTION__);
	new_dir = NULL;
	while (new_dir == NULL)
	{
		vec_delete(&g_data.tmp);
		new_dir = getcwd(g_data.tmp.buffer, g_data.tmp.alloc_len);
		if (new_dir == NULL && (errno == ENOMEM || errno == ERANGE))
		{
			print_debug("[INFO] msh_cd: resize buffer for getcwd\n");
			vec_resize(&g_data.tmp);
		}
		else if (new_dir == NULL)
		{
			msh_return(0, 1, strerror(errno), __FUNCTION__);
			return ;
		}
	}
	printf("%s\n", new_dir);
}

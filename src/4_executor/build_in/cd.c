/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:06:29 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 15:18:56 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// #include <sys/types.h>

#include <dirent.h>
#include <errno.h>
#include <string.h>

#include <sys/stat.h>
#include "env_utils.h"

int	make_new_dir(char *new_dir)
{
	if (!g_data.tmp.alloc_len)
		vec_resize(&g_data.tmp);
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
			return (msh_return(0, 1, strerror(errno), __FUNCTION__));
	}
	if (DEBUG_PRINT)
		printf("[INFO] msh_cd new dir [%s]\n", new_dir);
	env_set("PWD", new_dir, 1);
	updt_env();
	return (msh_return(1, 0, NULL, __FUNCTION__));
}

int	msh_cd(char **args)
{
	char *new_dir;
	int res;

	new_dir = args[1];
	if (!new_dir)
		new_dir = env_get_content("HOME");
	res = chdir(new_dir);
	if (res != 0)
		return (msh_return(0, 1, strerror(errno), __FUNCTION__));
	return (make_new_dir(new_dir));
}
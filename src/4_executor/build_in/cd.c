/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:06:29 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 14:42:56 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// #include <sys/types.h>

#include <dirent.h>
#include <errno.h>
#include <string.h>

// #include <sys/types.h>
#include <sys/stat.h>
#include "env_utils.h"
// #include <unistd.h>

//opendir, readdir, closedir,

//CHANGE DIR
//CHANGE PATH
int	msh_cd(char **args)
{
	char s[100];
	char *new_dir = args[1];
	if (!new_dir)
		new_dir = env_get_content("HOME");

    printf("%s\n", getcwd(s, 100));
	int res = chdir(new_dir);
    printf("%s\n", getcwd(s, 100));
	
	env_set("PWD", s, 1);
	
	if (res != 0)
		return (msh_exit(0, errno, strerror(errno)));
	return (1);
}

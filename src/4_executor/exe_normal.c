/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:50:35 by awillems          #+#    #+#             */
/*   Updated: 2022/06/24 12:26:12 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "lib_str.h"

int	get_path_len(char *cmd, int i)
{
	int len = 0;

	if (i != 0 && cmd[i - 1] != ':')
		return (0);
	while (cmd[i + len] && cmd[i + len] != ':')
		len++;
	return (len);
}

char *find_path(char *cmd)
{
	char *path = getenv("PATH");
	t_vec *vec = &g_data.tmp;
	int		len = ft_strlen(path);
	
	for (int i = 0; i < len; i++)
	{
		if (get_path_len(path, i) != 0)
		{
			vec_delete(vec);
			vec_fill(vec, FIXED_LEN, path + i, get_path_len(path, i));
			vec_fill(vec, MULTI, 2, "/", cmd);
			if (access((char *) vec->buffer, X_OK) == 0)
			{
				printf("=> %s\n", (char *) vec->buffer);
				break ;
			}
		}
	}
	

	
	vec_delete(vec);
	
	(void) cmd;
	(void) vec;
	(void) path;
	return (NULL);
}

void	exe_normal(char *cmd, char **args, char **envp)
{
	char *path = find_path(cmd);

	(void) path;
	(void) cmd;
	(void) args;
	(void) envp;
}
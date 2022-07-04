/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:50:35 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 15:54:41 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_str.h"
#include "env_utils.h"

int	get_path_len(char *cmd, int i)
{
	int	len;

	len = 0;
	if (i != 0 && cmd[i - 1] != ':')
		return (0);
	while (cmd[i + len] && cmd[i + len] != ':')
		len++;
	return (len);
}

char	*find_path(char *cmd, char *path, t_vec *vec)
{
	const int	len = ft_strlen(path);
	int			i;

	i = -1;
	while (++i < len)
	{
		if (get_path_len(path, i) == 0)
			continue ;
		vec_delete(vec);
		vec_fill(vec, FIXED_LEN, path + i, get_path_len(path, i));
		vec_fill(vec, MULTI, 2, "/", cmd);
		if (access((char *) vec->buffer, X_OK) == 0)
			return (vec->buffer);
	}
	vec_delete(vec);
	return (NULL);
}

void	exe_normal(char *cmd, char **args, char **envp)
{
	args[0] = find_path(cmd, env_get_content("PATH"), &g_data.tmp);
	execve(args[0], args, envp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_build_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:42:12 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 17:01:13 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_str.h"
#include "vec_utils.h"
#include "env_utils.h"
#include "build_in.h"
#include <errno.h>
#include <string.h>

static void	fd_check(int i)
{
	if (i == -1)
		msh_exit(1, strerror(errno), __FUNCTION__);
}

void	create_backup(int new_fd, int old_fd, int *backup)
{
	if (new_fd != old_fd)
	{
		*backup = dup(old_fd);
		fd_check(*backup);
		fd_check(dup2(new_fd, old_fd));
	}
}

void	use_backup(int new_fd, int old_fd, int backup)
{
	if (new_fd != old_fd)
	{
		fd_check(dup2(backup, old_fd));
		fd_check(close(backup));
		fd_check(close(new_fd));
	}
}

int	is_build_in(char *cmd)
{
	int			i;
	const char	*buildins[NB_BUILD_IN] = {
		"cd", "pwd", "echo",
		"export", "unset", "env",
		"exit",
		"dmsh"
	};

	i = -1;
	while (++i < NB_BUILD_IN)
	{
		if (ft_strlen(cmd) == ft_strlen(buildins[i])
			&& ft_strcmp(cmd, buildins[i]) == 0)
			return (i);
	}
	return (-1);
}

int	exe_build_in(char **args, int index, int fds[2])
{
	int					backup[2];
	const t_build_in	build_in_func[NB_BUILD_IN] = {
		msh_cd, msh_pwd, msh_echo,
		msh_export, msh_unset, msh_env,
		msh_exit_cmd,
		dmsh
	};

	create_backup(fds[0], STDIN_FILENO, &backup[0]);
	create_backup(fds[1], STDOUT_FILENO, &backup[1]);
	build_in_func[index](args);
	use_backup(fds[0], STDIN_FILENO, backup[0]);
	use_backup(fds[1], STDOUT_FILENO, backup[1]);
	return (1);
}

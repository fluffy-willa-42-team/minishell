/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_build_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:42:12 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 12:00:52 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_str.h"
#include "vec_utils.h"
#include "env_utils.h"
#include "build_in.h"

int	is_build_in(char *cmd)
{
	int					i;
	const char			*buildins[NB_BUILD_IN] = {
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

void	create_backup(int new_fd, int old_fd, int *backup)
{
	if (new_fd != old_fd)
	{
		*backup = dup(old_fd);
		dup2(old_fd, new_fd);
		close(new_fd);
		fprintf(stderr, "(%d => %d) [%d]\n", old_fd, new_fd, *backup);
	}
}

void	use_backup(int new_fd, int old_fd, int backup)
{
	if (new_fd != old_fd)
	{
		dup2(old_fd, backup);
		close(backup);
		fprintf(stderr, "(%d => %d) [%d]\n", old_fd, backup, new_fd);
	}
}

int	exe_build_in(char **args, int index, int fds[2])
{
	const t_build_in	build_in_func[NB_BUILD_IN] = {
		msh_cd, msh_pwd, msh_echo,
		export, msh_unset, env,
		msh_exit_cmd,
		dmsh
	};
	int backup[2];

	fprintf(stderr, "[%d, %d]\n", fds[0], fds[1]);
	create_backup(fds[0], STDIN_FILENO, backup);
	create_backup(fds[1], STDOUT_FILENO, backup + 1);
	build_in_func[index](args);
	use_backup(fds[0], STDIN_FILENO, backup[0]);
	use_backup(fds[1], STDOUT_FILENO, backup[1]);
	return (1);
}

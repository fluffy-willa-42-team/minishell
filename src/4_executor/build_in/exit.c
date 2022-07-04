/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:06:29 by awillems          #+#    #+#             */
/*   Updated: 2022/07/04 13:50:24 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_is_check.h"
#include "lib_put_fd.h"
#include "lib_atoi.h"

void	msh_exit_cmd(char **args)
{
	int	i;

	i = 0;
	if (!args || !args[0])
		msh_exit(1, "[ERROR] msh_exit_cmd: args NULL", __FUNCTION__);
	if (!args[1])
		msh_exit(0, "exit", __FUNCTION__);
	while (args[1][i])
	{
		if (!ft_isdigit(args[1][i]))
		{
			ft_putstr_fd("exit\nminishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
			msh_exit(255, NULL, __FUNCTION__);
		}
		i++;
	}
	if (!args[2])
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		msh_exit(ft_atoi(args[1]), NULL, __FUNCTION__);
	}
	ft_putstr_fd("exit\n", STDERR_FILENO);
	msh_return(1, 1, "exit: too many arguments", __FUNCTION__);
}

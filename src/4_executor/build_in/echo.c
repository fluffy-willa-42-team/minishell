/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:06:29 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 15:39:07 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_put_fd.h"
#include "lib_str.h"

static int	get_nb_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		i++;
	return (i);
}

int	msh_echo(char **args)
{
	const int nb_args = get_nb_args(args);
	int	do_endl;
	int	is_first;

	if (nb_args < 1)
		return (0);
	int i = 0;
	do_endl = 1;
	if (ft_strlen(args[1]) == 2 && ft_strcmp(args[1], "-n") == 0)
	{
		do_endl = 0;
		i++;
	}
	is_first = 1;
	while (++i < nb_args)
	{
		if (i == nb_args - 1 && do_endl)
			ft_putendl_fd(args[i], STDOUT_FILENO);
		else
			ft_putstr_fd(args[i], STDOUT_FILENO);
		if (i < nb_args - 1)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	return (1);
}

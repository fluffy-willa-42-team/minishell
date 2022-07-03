/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:06:29 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 17:03:52 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_exit_cmd(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		printf("%s\n", args[i]);
	}
}

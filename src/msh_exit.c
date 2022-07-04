/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:03:50 by awillems          #+#    #+#             */
/*   Updated: 2022/07/04 13:31:57 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_put_fd.h"

int	msh_return(int return_value, int exit_code, char *message, const char *fct)
{
	g_data.last_exit_code = exit_code;
	if (DEBUG_PRINT)
		printf("%s:\n", fct);
	if (exit_code)
	{
		ft_putstr_fd("minishell: ", STDOUT_FILENO);
		ft_putstr_fd(message, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	return (return_value);
}

int	msh_exit(unsigned char exit_code, char *message, const char *fct)
{
	if (DEBUG_PRINT)
		printf("%s:\n", fct);
	if (exit_code && message)
	{
		ft_putstr_fd("minishell: ", STDOUT_FILENO);
		ft_putstr_fd(message, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	exit (exit_code);
}

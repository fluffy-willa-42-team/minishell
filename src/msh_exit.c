/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:03:50 by awillems          #+#    #+#             */
/*   Updated: 2022/07/04 16:04:36 by mahadad          ###   ########.fr       */
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
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (return_value);
}

void	empty_g_data(void);
void	free_g_data(int free_line);

int	msh_exit(unsigned char exit_code, char *message, const char *fct)
{
	empty_g_data();
	free_g_data(0);
	if (DEBUG_PRINT)
		printf("%s:\n", fct);
	if (exit_code && message)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	exit (exit_code);
}

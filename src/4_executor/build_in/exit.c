/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:06:29 by awillems          #+#    #+#             */
/*   Updated: 2022/07/04 14:35:08 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_is_check.h"
#include "lib_put_fd.h"
#include <limits.h>

void static	long_explosion(char *nbr)
{
	ft_putstr_fd("exit\nminishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(nbr, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	msh_exit(255, NULL, __FUNCTION__);
}

/*
* SYNOPSIS
*   #include <stdlib.h>
* 
*   int
*   atoi(const char *str);
* 
* DESCRIPTION
*   The atoi() function converts the initial portion of the string pointed to
*   by str to int representation.
* 
*   It is equivalent to:
* 
*     (int)strtol(str, (char **)NULL, 10);
* 
*   While the atoi() function uses the current locale, the atoi_l() function
*   may be passed a locale directly. See xlocale(3) for more information.
* 
* IMPLEMENTATION NOTES
*   The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.
* 
*   The strtol() and strtol_l() functions are recommended instead of atoi()
*   and atoi_l() functions, especially in new code.
* 
* ERRORS
*   The function atoi() need not affect the value of errno on an error.
*/

int	local_ft_atoi(char *str, char *backup)
{
	unsigned long	nbr;
	unsigned long	cutoff;
	int				cutlim;
	int				isneg;

	nbr = 0;
	isneg = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	isneg = (*str == '-');
	str += (isneg || *str == '+');
	cutoff = (unsigned long)(LONG_MAX / 10);
	cutlim = (int)(LONG_MAX % 10);
	while (ft_isdigit((int)*str))
	{
		if (nbr > cutoff || (nbr == cutoff && (int)(*str - '0') > cutlim))
			long_explosion(backup);
		nbr *= 10;
		nbr += (*str - '0');
		str++;
	}
	return ((int []){nbr, -nbr}[isneg]);
}

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
		if (!ft_isdigit(args[1][i]) && args[1][0] != '-')
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
		msh_exit(local_ft_atoi(args[1], args[1]), NULL, __FUNCTION__);
	}
	ft_putstr_fd("exit\n", STDERR_FILENO);
	msh_return(1, 1, "exit: too many arguments", __FUNCTION__);
}

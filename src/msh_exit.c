/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:03:50 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 09:59:49 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_exit(int return_value, int exit_code, char *message, const char *fct)
{
	g_data.last_exit_code = exit_code;
	//TODO check if we can free in fork child ?
	//TODO free all vec.
	if (DEBUG_PRINT)
		printf("%s: ", fct);
	if (exit_code)
		printf("Error: %s\n", message);
	return (return_value);
}

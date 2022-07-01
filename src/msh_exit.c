/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:03:50 by awillems          #+#    #+#             */
/*   Updated: 2022/07/01 12:04:46 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_exit(int return_value, int exit_code, char *message)
{
	g_data.last_exit_code = exit_code;
	fprintf(stderr, "Error: %s\n", message);
	return (return_value);
}

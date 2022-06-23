/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:27:27 by awillems          #+#    #+#             */
/*   Updated: 2022/06/23 12:10:02 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_put_fd.h"

void	free_g_data(void);

void	exit_minishell(int code, char *message)
{
	if (code != 0)
		ft_putendl_fd(message, 2);
	free_g_data();
	exit(code);
}

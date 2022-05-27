/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:36:24 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 09:48:51 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_data;

int	init_data(void)
{
	g_data.env_path = NULL;
	g_data.lexed_comands = vec_init(sizeof(char));
	if (!g_data.lexed_comands.buffer)
		return (0);
	return (1);
}

int	minishell(void)
{
	if (!init_data())
		return (0);
	return (1);
}

int	main(void)
{
	return (!minishell());
}

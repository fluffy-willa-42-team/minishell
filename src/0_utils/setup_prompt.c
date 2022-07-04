/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sigaction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:08:41 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 16:19:29 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	setup_prompt_start(t_vec *vec, int ac, char **av)
{
	if (ac > 1)
	{
		if (!vec_fill(vec, MULTI, 3, "(", av[1], ")> "))
			return (0);
	}
	else if (!vec_fill(vec, DEFAULT, PROMPT_START))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:48:09 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 10:49:02 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

void	print_env(char *start, char *sep, char *end)
{
	size_t i = -1;

	setbuf(stdout, NULL);//TODO remove
	while (++i < g_data.env.len)
	{
		t_env *elem = vec_get_t_env(i);
		printf("%s%.*s%s%s%s\n",
			start, elem->env_len, elem->content.buffer, sep,
			elem->content.buffer + elem->env_len + 1, end);
	}
}

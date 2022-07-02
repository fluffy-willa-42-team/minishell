/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:48:09 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 18:20:15 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"
#include "vec_utils.h"

void	print_env(char *start, char *sep, char *end)
{
	size_t	i;
	t_env	*elem;

	i = -1;
	while (++i < g_data.env.len)
	{
		elem = vec_get_t_env(i);
		printf("%s%.*s%s%s%s\n",
			start, elem->env_len, elem->content.buffer, sep,
			elem->content.buffer + elem->env_len + 1, end);
	}
}

#ifdef DEBUG_PRINT

void	print_env_s(void)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (i < g_data.env_s.alloc_len)
	{
		tmp = vec_get_t_env_str(i);
		if (tmp)
		{
			printf("[%2lu]{%2d}(%-20lu)[%.32s]\n",
				i, vec_get_t_env_raw(i)->env_len, vec_get_t_env_raw(i)->token, tmp);
		}
		else
			printf("FUK!\n");
		i++;
	}
	printf("\n");
}

#endif

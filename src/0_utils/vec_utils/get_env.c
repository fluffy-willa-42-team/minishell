/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:30:07 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/28 14:30:20 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

t_env	*vec_get_t_env(int index)
{
	return ((t_env *)vec_get(&g_data.env_s, index));
}

char	*vec_get_env_str(int index)
{
	return ((char *)vec_get_t_env(index)->content.buffer);
}
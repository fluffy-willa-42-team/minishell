/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:53:58 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/02 11:04:58 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

/**
 * @brief Will destroy the env vector and pop.
 *        WARN! If the content dont exist will segfault !! //TODO check 
 */
t_vec	*env_pop(t_vec *vec, int index)
{
	vec_destroy(&vec_get_t_env(index)->content);
	return (vec_pop(vec, index));
}

/**
 * @brief Will erase all content and set `token` and `env_len` to `0`.
 *        WARN! If the content dont exist will segfault !! //TODO check 
 */
void	env_unset(t_env *env)
{
	vec_delete(&env->content);
	env->env_len = 0;
	env->token = 0;
}


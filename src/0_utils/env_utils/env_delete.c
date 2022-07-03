/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:53:58 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/03 10:31:40 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"
#include "vec_utils.h"

// /**
//  * @brief Will destroy the env vector and pop.
//  *        WARN! If the content dont exist will segfault !! //TODO check 
//  */
// t_vec	*env_pop(t_vec *vec, int index)
// {
// 	if (DEBUG_PRINT)
// 		printf("[INFO] env_pop: DESTROY [%s]\n",
// 			(char *)vec_get_t_env(index)->content.buffer);
// 	vec_destroy(&vec_get_t_env(index)->content);
// 	return (vec_pop(vec, index));
// }

/**
 * @brief Will erase all content and set `token` and `env_len` to `0`.
 */
void	env_unset(t_env *env)
{
	if (!env || !env->content.buffer)
	{
		if (DEBUG_PRINT)
			printf("[INFO] env_unset: delete [NULL]\n");
		return ;
	}
	if (DEBUG_PRINT)
		printf("[INFO] env_unset: delete [%s]\n", (char *) env->content.buffer);
	vec_delete(&env->content);
	env->env_len = 0;
	env->token = 0;
}


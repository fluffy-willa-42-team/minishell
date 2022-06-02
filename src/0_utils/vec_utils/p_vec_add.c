/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_vec_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:02:19 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/02 11:23:40 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

#include <errno.h>  /* strerror */
#include <string.h> /* strerror */

/**
 * @brief Protected `vec_add`.   Will check if vec_add dont return a fail
 *        allocation, if is the case will call `msh_exit` for a clean exit
 *        failure.
 */
t_vec	*p_vec_add(t_vec *vec, void *new_content)
{
	void	*addr;

	addr = vec_add(vec, new_content);
	if (addr == NULL)
		msh_exit(EXIT_FAILURE, strerror(errno));
	return ((t_vec *)addr);
}
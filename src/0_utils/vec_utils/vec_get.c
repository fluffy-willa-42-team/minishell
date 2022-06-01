/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:08:26 by awillems          #+#    #+#             */
/*   Updated: 2022/06/01 10:36:55 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

#include <stdio.h>

char	vec_get_char(t_vec *vec, int index)
{
	if (!vec_get(vec, index))
		return (0);
	return (((char *) vec_get(vec, index))[0]);
}

/**
 * @brief Get raw index of the buffer to `char *`.
 * 
 * @param index The raw index of the buffer
 */
char	*vec_get_str(t_vec *vec, int index)
{
	return (((char *) vec_get(vec, index)));
}

/**
 * @brief Get the struct from the ptr tab
 * 
 * @return t_instr* return the t_instr address
 */
t_instr	*vec_get_instr(t_vec *vec, int index)
{
	return (((t_instr *) vec_get(vec, index)));
}

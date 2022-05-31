/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:08:26 by awillems          #+#    #+#             */
/*   Updated: 2022/05/31 14:33:58 by awillems         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:08:26 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 13:49:25 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

char	vec_get_char(t_vec *vec, int index)
{
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

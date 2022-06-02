/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:08:26 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 14:21:55 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

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
 * @brief Get raw index of the buffer to `char *`.
 * 
 * @param index The raw index of the buffer
 */
char	*vec_get_str_array(t_vec *vec, int index)
{
	if (!vec_get(vec, index))
		return (NULL);
	return (*((char **) vec_get(vec, index)));
}

char	*vec_get_str_array_raw(t_vec *vec, int index)
{
	if (!vec_get(vec, index))
		return (NULL);
	return (*((char **) vec_get_raw(vec, index)));
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

t_instr	*vec_get_instr_raw(t_vec *vec, int index)
{
	return (((t_instr *) vec_get_raw(vec, index)));
}

/**
 * @brief Get the arg vector.
 * 
 * @param index The index of element.
 * @return t_vec* Return a ptr to the vector.
 */
t_vec	*get_instr_arg(int index)
{
	return (&(vec_get_instr(&g_data.lexed_instr, index)->arg));
}

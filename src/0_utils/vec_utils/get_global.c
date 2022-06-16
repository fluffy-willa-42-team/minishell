/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_global.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:03:04 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 13:03:11 by awillems         ###   ########.fr       */
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

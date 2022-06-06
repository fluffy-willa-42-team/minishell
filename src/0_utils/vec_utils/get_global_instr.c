/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_global_instr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:06:36 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 12:36:21 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

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




/** @brief get instr_list[ index ] */
t_instr	*get_instr(int index)
{
	return (((t_instr *) vec_get(get_instr_list(), index)));
}

/** @brief get instr_list[ index ].arg */
t_vec	*get_instr_arg(int index)
{
	return (&(get_instr(index)->arg));
}

/** @brief get instr_list[ instr_index ].arg[ arg_index ] */
char	*get_instr_arg_elem(int instr_index, int arg_index)
{
	if (!vec_get(get_instr_arg(instr_index), arg_index))
		return (NULL);
	return (*((char **) vec_get(get_instr_arg(instr_index), arg_index)));
}

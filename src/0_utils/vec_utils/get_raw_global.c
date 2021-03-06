/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_global.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:02:16 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 12:57:21 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

/** @brief get raw instr_list[ index ] */
t_instr	*get_raw_instr(int index)
{
	return (((t_instr *) vec_get_raw(get_instr_list(), index)));
}

/** @brief get raw instr_list[ index ].arg */
t_vec	*get_raw_instr_arg(int index)
{
	return (&(get_instr(index)->arg));
}

/** @brief get raw instr_list[ instr_index ].arg[ arg_index ] */
char	*get_raw_instr_arg_elem(int instr_index, int arg_index)
{
	if (!vec_get(get_instr_arg(instr_index), arg_index))
		return (NULL);
	return (*((char **) vec_get_raw(get_instr_arg(instr_index), arg_index)));
}

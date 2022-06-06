/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_global.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:06:36 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 12:03:51 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

/** @brief get instr_list */
t_vec	*get_line(void)
{
	return (&g_data.lexed_command);
}

/** @brief get instr_list */
t_vec	*get_instr_list(void)
{
	return (&g_data.lexed_instr);
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
	return (vec_get_str_array(&get_instr(instr_index)->arg, arg_index));
}

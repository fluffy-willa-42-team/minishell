/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:34:40 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 13:14:46 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

t_vec 	*vec_add_char_ptr(t_vec *vec, char *str)
{
	return (p_vec_add(vec, &str));
}

/**
 * @brief 
 * 
 * @param vec The instr struct vector.
 * @param type The type of element. //TODO make the macro
 * @return t_vec* 
 */
t_vec	*vec_add_instr(t_vec *vec, int type)
{
	t_instr	new;

	new.arg = vec_init(sizeof(char *));
	new.arg.rate = 8;
	new.type = type;
	new.state = 1;
	vec_add(vec, &new);
	return (vec);
}
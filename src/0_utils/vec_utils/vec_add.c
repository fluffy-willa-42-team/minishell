/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:34:40 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 11:06:13 by mahadad          ###   ########.fr       */
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
	vec_add(vec, &new);
	return (vec);
}
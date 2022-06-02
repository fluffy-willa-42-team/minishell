/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:34:40 by awillems          #+#    #+#             */
/*   Updated: 2022/06/02 08:38:58 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

t_vec 	*vec_add_char_ptr(t_vec *vec, char *str)
{
	return (vec_add(vec, &str));
}

t_vec	*vec_add_instr(t_vec *vec, int type)
{
	t_instr	new;

	new.arg = vec_init(sizeof(char *));
	new.arg.rate = 8;
	new.type = type;
	vec_add(vec, &new);
	return (vec);
}
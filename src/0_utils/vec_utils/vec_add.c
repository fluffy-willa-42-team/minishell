/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:34:40 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 11:54:39 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

t_vec 	*vec_add_char_ptr(t_vec *vec, char *str)
{
	return (vec_add(vec, &str));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:08:26 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 11:13:40 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vec_utils.h"

char	vec_get_char(t_vec *vec, int index)
{
	return (((char *) vec_get(vec, index))[0]);
}

char	*vec_get_str(t_vec *vec, int index)
{
	return (((char *) vec_get(vec, index)));
}

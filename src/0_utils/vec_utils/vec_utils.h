/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:12:43 by awillems          #+#    #+#             */
/*   Updated: 2022/05/31 17:26:53 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_UTILS_H
# define VEC_UTILS_H

# include "minishell.h"
# include "vector_lib.h"

char	vec_get_char(t_vec *vec, int index);
char	*vec_get_str(t_vec *vec, int index);
t_instr	*vec_get_instr(t_vec *vec, int index);
#endif
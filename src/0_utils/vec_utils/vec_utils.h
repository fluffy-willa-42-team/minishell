/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:12:43 by awillems          #+#    #+#             */
/*   Updated: 2022/06/01 14:38:33 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_UTILS_H
# define VEC_UTILS_H

# include "minishell.h"
# include "vector_lib.h"

t_vec 	*vec_add_char_ptr(t_vec *vec, char *str);
t_vec 	*vec_add_instr(t_vec *vec, t_instr new_instr);

char	vec_get_char(t_vec *vec, int index);
char	*vec_get_str(t_vec *vec, int index);
char	*vec_get_str2(t_vec *vec, int index);
t_instr	*vec_get_instr(t_vec *vec, int index);
#endif
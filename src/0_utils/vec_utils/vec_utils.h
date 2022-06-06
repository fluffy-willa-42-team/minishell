/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:12:43 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 13:11:04 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_UTILS_H
# define VEC_UTILS_H

# include "minishell.h"
# include "vector_lib.h"

t_vec 	*vec_add_char_ptr(t_vec *vec, char *str);
t_vec	*vec_add_instr(t_vec *vec, int type);

char	vec_get_char(t_vec *vec, int index);
char	*vec_get_str(t_vec *vec, int index);
char	*vec_get_str_array(t_vec *vec, int index);
char	*vec_get_str_array_raw(t_vec *vec, int index);
t_instr	*vec_get_instr(t_vec *vec, int index);
t_instr	*vec_get_instr_raw(t_vec *vec, int index);
t_vec	*p_vec_add(t_vec	*vec, void *new_content);
t_vec	*get_instr_arg(int index);
t_vec	*get_instr_arg_raw(int index);
char	*get_vec_instr_arg(int instr_index, int arg_index);

#endif
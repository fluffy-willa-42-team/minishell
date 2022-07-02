/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:12:43 by awillems          #+#    #+#             */
/*   Updated: 2022/07/01 17:26:40 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_UTILS_H
# define VEC_UTILS_H

# include "minishell.h"
# include "vector_lib.h"
# include "env_utils.h"

t_vec	*vec_add_char_ptr(t_vec *vec, char *str);
t_vec	*vec_add_int(t_vec *vec, int x);
t_vec	*vec_add_instr(t_vec *vec, int type);

char	vec_get_char(t_vec *vec, int index);
char	*vec_get_str(t_vec *vec, int index);
char	*vec_get_str_array(t_vec *vec, int index);
char	*vec_get_str_array_raw(t_vec *vec, int index);

t_vec	*get_line(void);
char	get_cmd_char(int index);
char	*get_cmd_str(int index);

t_vec	*get_line(void);
t_vec	*get_instr_list(void);
t_instr	*get_instr(int index);
t_vec	*get_instr_arg(int index);
char	*get_instr_arg_elem(int instr_index, int arg_index);

t_instr	*get_raw_instr(int index);
t_vec	*get_raw_instr_arg(int index);
char	*get_raw_instr_arg_elem(int instr_index, int arg_index);

t_env	*vec_get_t_env(int index);
t_env	*vec_get_t_env_raw(int index);
char	*vec_get_t_env_str(int index);

t_env	*vec_add_new_env(char *name, char *content);

#endif
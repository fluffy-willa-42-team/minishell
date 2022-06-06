/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:12:43 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 12:30:31 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_UTILS_H
# define VEC_UTILS_H

# include "minishell.h"
# include "vector_lib.h"

t_vec 	*vec_add_char_ptr(t_vec *vec, char *str);
t_vec	*vec_add_instr(t_vec *vec, int type);

t_vec	*get_line(void);
t_vec	*get_instr_list(void);
t_instr	*get_instr(int index);
t_vec	*get_instr_arg(int index);
char	*get_instr_arg_elem(int instr_index, int arg_index);

t_instr	*get_raw_instr(int index);
t_vec	*get_raw_instr_arg(int index);
char	*get_raw_instr_arg_elem(int instr_index, int arg_index);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:17:09 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/02 10:52:28 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

#include "minishell.h"

typedef struct s_env {
	unsigned long	token;
	int				env_len;
	t_vec			content;
}				t_env;

#include "vec_utils.h"

unsigned long	djb2_hash(char *str, int len);

void			init_env(char **env);

t_env			*env_get(char *name);
char			*env_get_content(char *name);
void			env_unset(t_env *env);
t_vec			*env_pop(t_vec *vec, int index);
t_env			*env_set(char *name, char *value, int overwrite);
t_vec			*updt_env(void);//TODO ENV changer l'emplacement et de nom

void			print_env_s(void);//TODO REMOVE !!!!!!!!!
void			print_env(char *start, char *sep, char *end);//TODO ENV changer l'emplacement

#endif /* ENV_UTILS_H */

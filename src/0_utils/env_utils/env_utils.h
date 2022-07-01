/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:17:09 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/01 16:52:03 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

#include "minishell.h"
#include "vec_utils.h"

typedef struct s_env {
	unsigned long	token;
	int				env_len;
	t_vec			content;
}				t_env;

unsigned long	djb2_hash(char *str, int len);

void			init_env(char **env);

t_env			*env_get(char *name);
char			*env_get_content(char *name);
void			env_unset(t_env *env);
t_vec			*env_pop(t_vec *vec, int index);
t_env			*env_set(char *name, char *value, int overwrite);
t_vec			*updt_env(void);//TODO ENV changer l'emplacement et de nom

void	print_env_s(void);//TODO REMOVE !!!!!!!!!
void			print_env(void);//TODO ENV changer l'emplacement

#endif /* ENV_UTILS_H */

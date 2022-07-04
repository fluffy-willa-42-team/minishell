/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:17:09 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/02 18:44:04 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "vector_lib.h"

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
// t_vec			*env_pop(t_vec *vec, int index);//TODO
t_env			*env_set(char *name, char *value, int overwrite);
t_vec			*updt_env(void);//TODO ENV changer l'emplacement et de nom

void			print_env(char *start, char *sep, char *end);

# ifdef DEBUG_PRINT

void			print_env_s(void);
# endif /* DEBUG_PRINT */

#endif /* ENV_UTILS_H */

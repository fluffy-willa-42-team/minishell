/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:17:09 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/27 14:39:57 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

#include "minishell.h"
#include "vec_utils.h"

typedef struct s_env {
	int		token;
	int		env_len;
	t_vec	content;
}				t_env;

void	init_env(char **env);

#endif /* ENV_UTILS_H */

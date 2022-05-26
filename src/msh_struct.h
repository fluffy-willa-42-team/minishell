/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:52 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/26 11:19:01 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_STRUCT_H
# define MSH_STRUCT_H

# include <signal.h>
# include "vector_lib.h"

typedef struct sigaction t_sigaction;

typedef struct s_minishell
{
	char	*env_path;
	t_vec	str_list;
	t_vec	exec_list;
	t_vec	buff_input;
}				t_minishell;

extern t_minishell	g_data;

#endif
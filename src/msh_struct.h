/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:52 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/26 12:35:27 by awillems         ###   ########.fr       */
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
	t_vec	prompt_line_opened_char;
}				t_minishell;

extern t_minishell	g_data;

#endif
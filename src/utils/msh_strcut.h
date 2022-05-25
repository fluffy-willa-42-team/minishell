/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strcut.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:52 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/24 16:24:19 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_STRUCT_H
# define MSH_STRUCT_H

# include <signal.h>

typedef struct sigaction t_sigaction;

typedef struct s_minishell
{
	char	*env_path;
}				t_minishell;

#endif
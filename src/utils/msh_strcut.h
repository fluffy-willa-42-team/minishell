/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strcut.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:52 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/18 12:18:26 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

typedef struct sigaction t_sigaction;

typedef struct s_minishell
{
	t_sigaction	sig;
}				t_minishell;

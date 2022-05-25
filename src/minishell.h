/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:38:26 by awillems          #+#    #+#             */
/*   Updated: 2022/05/25 10:56:45 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */

# include "stdio.h"
# include "unistd.h"
# include "string.h"
# include "stdlib.h"
# include "signal.h"
# include "termios.h"
# include "sys/types.h"
# include "sys/stat.h"
# include "sys/time.h"
# include "sys/resource.h"
# include "sys/wait.h"
# include "sys/ioctl.h"
# include <readline/readline.h>
# include <readline/history.h>

# include "msh_struct.h"
# include "libft.h"

/* ************************************************************************** */

void	msh_bin_indexer(t_minishell *data);

#endif
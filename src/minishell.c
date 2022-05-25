/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:16:20 by awillems          #+#    #+#             */
/*   Updated: 2022/05/25 10:59:53 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "msh_prompt.h"
#include "msh_struct.h"
#include "msh_debug.h"
#include <stdlib.h>

t_minishell	data;

int	main(void)
{

	//DEBUG TODO REMOVE
	setbuf(stdout, NULL);
	msh_bin_indexer(&data);
	msh_prompt();
	//TODO make custom exit function that free stuff befor quit
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:16:20 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 16:24:43 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "msh_prompt.h"
#include "msh_strcut.h"
#include "msh_debug.h"
#include <stdlib.h>



int	main()
{
	t_minishell	data;

	//DEBUG TODO REMOVE
	setbuf(stdout, NULL);
	msh_bin_indexer(&data);
	msh_prompt();
	//TODO make custom exit function that free stuff befor quit
	return (0);
}

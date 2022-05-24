/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bin_indexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:26:44 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/24 16:27:31 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "msh_strcut.h"
#include "msh_debug.h"

static void	get_env(char *bin)
{

	bin = getenv("PATH");
	if (!bin)
		exit(EXIT_FAILURE);//TODO clean exit function
	if (MSH_DEBUG)
		printf("PATH: %s\n", bin);
}

void msh_bin_indexer(t_minishell *data)
{
	get_env(data->env_path);
	//TODO red tree
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:16:20 by awillems          #+#    #+#             */
/*   Updated: 2022/05/26 12:46:46 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_struct.h"
#include "msh_debug.h"
#include <stdlib.h>

void	msh_prompt(void);
void	msh_bin_indexer(t_minishell *data);

t_minishell	g_data;

int	main(void)
{
	g_data.prompt_line_opened_char = vec_init(sizeof(char));
	g_data.str_list = vec_init(sizeof(char));
	
	//DEBUG TODO REMOVE
	setbuf(stdout, NULL);
	// msh_bin_indexer(&);
	msh_prompt();
	//TODO make custom exit function that free stuff befor quit
	return (0);
}

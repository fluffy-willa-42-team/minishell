/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:12:41 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 11:15:06 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
// #include <stdlib.h>    /** getenv */
#include <stdio.h>

/**
 * @brief //TODO WIP
 * 
 * @param line 
 * @return char* 
 */
char *find_bin_path(char *line)
{
	(void)line;
	return ("WIP/bin/");
}


/**
 * @brief Set the binary path of the argument if its not already one and is not
 * the argument of the previous line (aka "<<")
 */
void	set_bin_path(t_vec *line, int index, int cmd_index)
{
	if (ft_strcmp(get_instr_arg_elem(cmd_index, 0), "<<"))
		printf("hello\n");
	
	// Check if the CMD is a bin with path
	if (access(vec_get_str(line, index), X_OK) != -1)
		return ;
	// find the good path
	vec_insert(line, DEFAULT, index, find_bin_path(vec_get_str(line, index)));
}
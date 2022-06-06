/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:12:41 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 14:13:24 by awillems         ###   ########.fr       */
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
int	set_bin_path(int line_index, int cmd_index)
{
	// static char *spec_elem[] = {"<<", "<", ">", ">>"};
	
	printf("[%d]%d\n", cmd_index, line_index);
	// if (cmd_index < 0)
	// 	for (int i = 0; i < 4; i++)
	// 		if (ft_strcmp(get_instr_arg_elem(cmd_index - 1, 0), spec_elem[i]))
	// 			return (0);
	
	// Check if the CMD is a bin with path
	if (access(get_cmd_str(line_index), X_OK) != -1)
		return (0);
	// find the good path
	char *path = find_bin_path(get_cmd_str(line_index));
	printf("=> %s\n", path);
	vec_insert(get_line(), DEFAULT, line_index, "MDR");
	return (ft_strlen(path));
}
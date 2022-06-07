/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:12:41 by awillems          #+#    #+#             */
/*   Updated: 2022/06/07 13:04:42 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"
// #include <stdlib.h>    /** getenv */
#include <stdio.h>

void	print_instr(size_t len);

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

// if (access(get_cmd_str(line_index), X_OK) != -1)
// 	return (0);

int	is_spec_elem(int cmd_index)
{
	static char *spec_elem[] = {"<<", "<", ">", ">>"};

	if (cmd_index < 1)
		return (1);
	for (int i = 0; i < 4; i++)
		if (ft_strcmp(spec_elem[i], get_instr_arg_elem(cmd_index - 1, 0)) == 0)
			return (0);
	return (1);
}

/**
 * @brief Set the binary path of the argument if its not already one and is not
 * the argument of the previous line (aka "<<")
 */
int	set_bin_path(int line_index, int cmd_index)
{
	// check if the previous instr is a special instruction
	if (!is_spec_elem(cmd_index))
		return (0);
	
	// Check if the CMD is a bin with path
	if (access(get_cmd_str(line_index), X_OK) != -1)
		return (0);
	
	// find the good path
	char *path = find_bin_path(get_cmd_str(line_index));

	// add the paths
	vec_insert(get_line(), DEFAULT, line_index, path);
	return (ft_strlen(path));
}

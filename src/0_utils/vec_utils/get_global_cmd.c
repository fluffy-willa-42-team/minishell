/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_global_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:29:45 by awillems          #+#    #+#             */
/*   Updated: 2022/06/06 12:58:19 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "minishell.h"

/** @brief get instr_list */
t_vec	*get_line(void)
{
	return (&g_data.lexed_command);
}

/** @brief get cmd[i] */
char	get_cmd_char(int index)
{
	if (!vec_get(get_line(), index))
		return (0);
	return (*((char *) vec_get(get_line(), index)));
}

/** @brief get &cmd[i] */
char	*get_cmd_str(int index)
{
	if (!vec_get(get_line(), index))
		return (0);
	return ((char *) vec_get(get_line(), index));
}

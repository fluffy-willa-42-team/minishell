/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:28:39 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/23 11:14:14 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"

void	close_fd(int (**pipe_ptr)[2], int index)
{
	if ((**pipe_ptr)[index] != index)
		close((**pipe_ptr)[index]);
}

void	move_buf(int (**pipe_ptr)[2], int index, int instr_index)
{
	printf("=> %d\n", (**pipe_ptr)[index]);
	if ((**pipe_ptr)[index] != -2)
	{
		get_instr(instr_index)->fds[index] = (**pipe_ptr)[index];
		(**pipe_ptr)[index] = -2;
	}
}

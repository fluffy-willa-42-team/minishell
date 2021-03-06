/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:28:39 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/02 17:33:01 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"
#include "lib_str.h"
#include "vec_utils.h"

void	close_fd(int (**pipe_ptr)[2], int index)
{
	if ((**pipe_ptr)[index] != index)
		close((**pipe_ptr)[index]);
}

void	move_buf(int (**pipe_ptr)[2], int index, int instr_index)
{
	if ((**pipe_ptr)[index] != -2)
	{
		get_instr(instr_index)->fds[index] = (**pipe_ptr)[index];
		(**pipe_ptr)[index] = -2;
	}
}

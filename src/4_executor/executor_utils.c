/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:45:30 by awillems          #+#    #+#             */
/*   Updated: 2022/06/30 10:39:04 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	set_fd_to_std(int fd, int output)
{
	if (fd != output)
	{
		fprintf(stderr, "%d => %d\n", fd, output);
		dup2(fd, output);
		close(fd);
	}
}

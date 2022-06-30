/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:45:30 by awillems          #+#    #+#             */
/*   Updated: 2022/06/30 12:57:57 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	set_fd_to_std(int fd[2], int input, int output)
{
	if (fd[0] != input)
	{
		fprintf(stderr, "%d => %d\n", fd[0], input);
		dup2(fd[0], input);
		close(fd[0]);
	}
	if (fd[1] != output)
	{
		fprintf(stderr, "%d => %d\n", fd[1], output);
		dup2(fd[1], output);
		close(fd[1]);
	}
}

void	close_fd_pipe(int fd[2])
{
	if (fd[0] != STDIN_FILENO)
		close(fd[0]);
	if (fd[1] != STDOUT_FILENO)
		close(fd[1]);
}

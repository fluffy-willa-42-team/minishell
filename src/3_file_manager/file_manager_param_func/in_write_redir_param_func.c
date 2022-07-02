/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_write_redir_param_func.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:18:35 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 17:49:02 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include "file_manager.h"
#include <errno.h>
#include "lib_str.h"
#include "lib_put_fd.h"
#include "vec_utils.h"

void	secundary_prompt(int fd, const char *delimitor)
{
	const size_t	len = ft_strlen(delimitor);
	char			*line_read;

	line_read = readline(SECUNDARY_PROMPT_START);
	while (line_read)
	{
		if (line_read && line_read[0])
		{
			if (len == ft_strlen(line_read)
				&& ft_strcmp(line_read, delimitor) == 0)
				break ;
			ft_putendl_fd(line_read, fd);
		}
		free(line_read);
		line_read = readline(SECUNDARY_PROMPT_START);
	}
	free(line_read);
}

void	redir_in_write(int instr_index, int (**pipe_ptr)[2], int **code_ptr)
{
	const char	*delimitor = get_instr_arg_elem(instr_index, 1);
	int			safety;

	if (DEBUG_PRINT)
		printf("REDIR IN WRITE\n");
	safety = pipe(get_instr(instr_index)->fds);
	if (safety == -1)
		**code_ptr = errno;
	secundary_prompt(get_instr(instr_index)->fds[1], delimitor);
	close(get_instr(instr_index)->fds[1]);
	(**pipe_ptr)[0] = get_instr(instr_index)->fds[0];
}

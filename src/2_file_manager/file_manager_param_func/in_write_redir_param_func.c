/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sep_param_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:18:35 by awillems          #+#    #+#             */
/*   Updated: 2022/06/21 13:27:18 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manager.h"
#include <readline/readline.h>

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
			ft_putstr_fd(line_read, fd);
			ft_putchar_fd('\n', fd);
		}
		free(line_read);
		line_read = readline(SECUNDARY_PROMPT_START);
	}
	free(line_read);
}

int	redir_in_write(int (**pipe_ptr)[2], int instr_index)
{
	const char	*delimitor = get_instr_arg_elem(instr_index, 1);

	printf("REDIR IN WRITE\n");
	pipe(get_instr(instr_index)->file_descriptor);
	secundary_prompt(get_instr(instr_index)->file_descriptor[1], delimitor);
	close(get_instr(instr_index)->file_descriptor[1]);
	(**pipe_ptr)[0] = get_instr(instr_index)->file_descriptor[0];
	return (1);
}

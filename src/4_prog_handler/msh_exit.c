/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:05:49 by awillems          #+#    #+#             */
/*   Updated: 2022/05/26 12:06:59 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_struct.h"
#include "msh_exit.h"
#include "libft.h"
#include <unistd.h>

/**
 * @brief Error handler macro.
 * [0][0][0]
 *  ^  ^
 *  |  |
 *  |  |-: If true -> `EXIT_FAILURE`. If false `EXIT_SUCCESS`.
 *  |-: If fisrt bit `true`  -> we exit the prog.
 *  |-: If fisrt bit `false` -> print error message.
 */

static void free_vec()
{
	//TODO check if the vec.buffer == NULL to avoid segfault.
	vec_delete(&g_data.str_list);
	vec_delete(&g_data.exec_list);
	vec_delete(&g_data.buff_input);
}

static void free_exit()
{
	free_vec();
}

/**
 * @brief Check if the bit 2 is true or false to print in the stdout or stderr.
 */
static	void debug(int err, char *strerr)
{
	int fd;

	fd = (int []){STDIN_FILENO, STDERR_FILENO}[err & 0b010];
	ft_putstr_fd(strerr, fd);
}

void	msh_exit(int err, char *strerr)
{
	if (strerr)
		debug(err, strerr);
	if (err & 0b100)
		free_exit();
}
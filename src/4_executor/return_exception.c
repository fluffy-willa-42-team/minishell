/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_exception.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:51:18 by awillems          #+#    #+#             */
/*   Updated: 2022/06/23 13:02:57 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib_put_fd.h"
# include "minishell.h"
# include <string.h>
# include <errno.h>

int	msh_exception(int code)
{
	g_data.last_exit_code = code;
	if (code == 0)
		return (1);
	printf("%s: %s\n", g_data.cmd, strerror(code));
	return (0);
}
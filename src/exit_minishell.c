/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:45:53 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/02 11:06:56 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h> /** printf */
#include "libft.h" /** ft_strlen */
#include "vec_utils.h"

/**
 * @brief [internal] Free ☭ our ☭ function from the capitalist allocation.
 * 
 */
static void	exit_minishell(void)
{
	vec_destroy(&g_data.lexed_command);
	vec_destroy(&g_data.lexed_instr);
	vec_destroy(&g_data.tmp);
	free(g_data.env_path);
}

/**
 * @brief Will print message on `stdout` if `exit_code` == `EXIT_SUCCESS`, if
 *        false will print on the `stderr`.   Free all allocation and exit
 *        return `exit_code`.
 * 
 * @param exit_code Exit code that will be return with `exit(exit_code);`
 * @param msg       Print a debug message, if null dont print.
 */
void	msh_exit(int exit_code, char *msg)
{
	int	fd;

	// If the exit code is not `EXIT_SUCCESS` print to the `stderr`.
	fd = (int []){STDERR_FILENO, STDOUT_FILENO}[exit_code == EXIT_SUCCESS];
	if (msg)
	{
		ft_putstr_fd(msg, fd);
		// If the string dont make newline @ the end, print newline.
		if (msg[ft_strlen(msg)] != '\n')
			ft_putstr_fd("\n", fd);
	}
	exit_minishell();
	exit(exit_code);
}
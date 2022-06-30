/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sigaction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:08:41 by awillems          #+#    #+#             */
/*   Updated: 2022/06/30 10:52:05 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <signal.h>

/**
 * @brief Function call by `sigaction` when catch signals.
 */
static void	sighandler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

/**
 * @brief Checker for the sigaction return.
 * 
 * @param debug_sigaction `int` that `sigation` return.
 * @param name Name of the signal macro.
 */
static void	msh_check_sigaction(int sigaction_return, char *name)
{
	(void) name;
	if (sigaction_return != -1)
	{
		return ;
	}
//TODO make a clean exit function, like msh_exit(EXIT_FAILURE, strerror(errno), <...>);
	exit(EXIT_FAILURE);
}

/**
 * @brief Set sigaction. For `C-c` (SIGINT) will clear the readline buff and 
 *          show up a new prompt.   Will ignore `C-\` (SIGQUIT).
 *
 */
void	set_sigaction(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;
	sigset_t			sig_set;

	sigemptyset(&sig_set);
	sigaddset(&sig_set, SIGINT);
	sigaddset(&sig_set, SIGQUIT);
	sigint.sa_handler = sighandler;
	sigint.sa_mask = sig_set;
	sigquit.sa_handler = SIG_IGN;
	sigquit.sa_mask = sig_set;
	msh_check_sigaction(sigaction(SIGINT, &sigint, NULL), "SIGINT");
	msh_check_sigaction(sigaction(SIGQUIT, &sigquit, NULL), "SIGQUIT");
}

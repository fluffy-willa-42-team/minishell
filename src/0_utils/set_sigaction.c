/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sigaction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:08:41 by awillems          #+#    #+#             */
/*   Updated: 2022/07/06 11:14:11 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

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
	if (sigaction_return != -1)
		return ;
	if (DEBUG_PRINT)
		printf("[ERROR] %s:%d %s fail\n", __FILE__, __LINE__, name);
	msh_exit(errno, strerror(errno), __FUNCTION__);
}

/**
 * @brief Set sigaction. For `C-c` (SIGINT) will clear the readline buff and 
 *          show up a new prompt.   Will ignore `C-\` (SIGQUIT).
 * @param is_child if true will unlock sigquit, if false block sigquit
 */
void	set_sigaction(int is_child)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;
	sigset_t			sig_set;

	sigemptyset(&sig_set);
	sigaddset(&sig_set, SIGINT);
	sigaddset(&sig_set, SIGQUIT);
	sigint.sa_handler = sighandler;
	sigint.sa_mask = sig_set;
	if (is_child)
		sigquit.sa_handler = SIG_DFL;
	else
		sigquit.sa_handler = SIG_IGN;
	sigquit.sa_mask = sig_set;
	msh_check_sigaction(sigaction(SIGINT, &sigint, NULL), "SIGINT");
	msh_check_sigaction(sigaction(SIGQUIT, &sigquit, NULL), "SIGQUIT");
}

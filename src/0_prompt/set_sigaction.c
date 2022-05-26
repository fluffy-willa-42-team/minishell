/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sigaction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:08:41 by awillems          #+#    #+#             */
/*   Updated: 2022/05/26 09:06:09 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_debug.h"
#include "libft.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>

/**
 * @brief Function call by `sigaction` when catch signals.
 */
static void	sighandler(int signum)
{
	if (signum == SIGINT)
	{
		/**
		 * Documentation about Redisplay
		 *   https://tiswww.case.edu/php/chet/readline/readline.html#SEC35
		 */

		write(1, "\n", 1);
		// Clear the current buffer.
		rl_replace_line("", 0);
		// Tell the update functions that we have moved onto a new line
		rl_on_new_line();
		// Change what's displayed on the screen to reflect the current contents of `PROMPT_TXT`.
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
	/**
	 * sigaction() returns `0` on success; on error, `-1` is returned, and
	 * `errno` is set to indicate the error.
	 */
	if (sigaction_return != -1)
	{
		if (MSH_DEBUG) printf("%s Ok\n", name);
		return ;
	}
	if (MSH_DEBUG)
		printf("%s [KO]: %d !!\n"
			"%s\n",
			name,
			sigaction_return,
			strerror(errno)
		);
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
	// Settings for the `C-c`
	struct sigaction	sigint;
	struct sigaction	sigquit;
	sigset_t			sig_set;

	/**
	 * Init mask, mask allow to specify a set of signal that aren't permitted
	 *   to iterrupt the handler.
	 */
	sigemptyset(&sig_set);
	sigaddset(&sig_set, SIGINT);
	sigaddset(&sig_set, SIGQUIT);

	// The function call when the signal is catch.
	sigint.sa_handler = sighandler;
	// Set the mask
	sigint.sa_mask = sig_set;

	// Ignore the `c-\` signal.
	sigquit.sa_handler = SIG_IGN;
	// Set the mask
	sigquit.sa_mask = sig_set;

	// Start to catch signal.
	msh_check_sigaction(sigaction(SIGINT, &sigint, NULL), "SIGINT");
	msh_check_sigaction(sigaction(SIGQUIT, &sigquit, NULL), "SIGQUIT");
}

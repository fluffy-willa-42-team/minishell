/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:44:08 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/19 17:11:56 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_prompt.h"

/**
 * @brief Function call by `sigaction` when catch signals.
 */
void sighandler(int signum)
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
 * @brief Set sigaction. For `C-c` (SIGINT) will clear the readline buff and 
 *          show up a new prompt.   Will ignore `C-\` (SIGQUIT).
 *
 */
void set_sigaction(void)
{
	// Settings for the `C-c`
	struct sigaction	sigint;
	struct sigaction	sigquit;
	sigset_t			sig_set;
	int					debug_sigaction;

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
	debug_sigaction = sigaction(SIGINT, &sigint, NULL);
	if (debug_sigaction != -1)
		printf("SIGINT Ok\n");
	else
		printf("SIGINT [KO]: %d !!\n%s\n", debug_sigaction, strerror(errno));

	debug_sigaction = sigaction(SIGQUIT, &sigquit, NULL);
	if (debug_sigaction != -1)
		printf("SIGQUIT Ok\n");
	else
		printf("SIGQUIT [KO]: %d !!\n%s\n", debug_sigaction, strerror(errno));
}

/**
 * @brief Start the prompt and set the signal action.
 */
void prompt (void)
{
	char	*line_read;

	set_sigaction();
	line_read = (char *) NULL;

	while (!line_read)
	{
		line_read = readline(PROMPT_TXT);
		if (line_read)
		{
			// Check if readline dont return a EOF aka `C-D`
			if (strlen(line_read))
			{
				//TODO run paser function
				printf("[%s]\n", line_read);
				free(line_read);
				line_read = NULL;
			}
			else
			{
				printf("        Empty line\n");
			}
		}
		else
		{
			printf("\n        null line_read\n");
			return ;
		}
		line_read = NULL;
	}
}
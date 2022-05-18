/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:16:20 by awillems          #+#    #+#             */
/*   Updated: 2022/05/18 14:28:15 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void prompt (void)
{
	char	*line_read;

	line_read = (char *) NULL;

	while (!line_read)
	{
		printf("\n   [LOG] start while\n");
		line_read = readline(PROMPT_TXT);
		printf("\n   [LOG] readline read\n");
		if (line_read)
		{
			printf("\n   [LOG] line_read true\n");
			// Check if readline dont return a EOF aka `C-D`
			if (strlen(line_read))
			{
				printf("\n   [LOG] strlen line_read true\n");
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

void sighandler(int signum)
{
	(void)signum;
	// printf("\nsignum get %d\n", signum);
	printf("\n%s", PROMPT_TXT);
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	rl_replace_line("",0);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	//DEBUG TODO REMOVE
	setbuf(stdout, NULL);

	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);


	prompt();
	//TODO make custom exit function that free stuff befor quit
	return (0);
}

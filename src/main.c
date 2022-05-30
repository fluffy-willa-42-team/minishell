/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:36:24 by awillems          #+#    #+#             */
/*   Updated: 2022/05/30 16:44:34 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	set_sigaction(void);
int		interpret_line(char *line);

t_minishell	g_data;

/**
 * @brief 
 * 
 */
void	alloc_instr(void)
{
	int		index;
	t_instr	*ptr;

	index = 0;
	printf("g_data.lexed_instr.len: %d\n", g_data.lexed_instr.len);
	// While index dont exeed the number of element in lexed_instr
	while (index < g_data.lexed_instr.len)
	{
		printf("index; %d\n", index);
		// Get the adress of the current element with index and cast to t_instr
		ptr = (t_instr *)vec_get(&g_data.lexed_instr, index);
		// Allocate the t_instr with a array of char
		ptr->arg = vec_init(sizeof(char *));

//TODO XXX WIP

		//Test dummy string
		char *test[7] = {
			"test 0",
			"test 1",
			"test 2",
			"test 3",
			"test 4"
		};
		int test_index = 0;
		while (test_index < 5)
		{
			// Cast the buffer to char array
			char **tmp = (char**)ptr->arg.buffer;
			// Change the address that the array pointing
			tmp[test_index] = test[test_index];
			test_index++;
		}
		index++;
	}
	printf("\nalloc done\n");
	index = 0;
	while (index < g_data.lexed_instr.len)
	{
		printf("\nindex; %d\n", index);
		// Get the adress of the current element with index and cast to t_vect
		ptr = (t_instr *)vec_get(&g_data.lexed_instr, index);

		int test_index = 0;
		while (test_index < 5)
		{
			char **str = (char **)ptr->arg.buffer;
			printf("[[%s]] ", str[test_index]);
			test_index++;
		}
		index++;
	}
	printf("\ncheck done\n");
}

/**
 * @brief Init the global var with all data.
 */
void	init_data(void)
{
	g_data.env_path = NULL;
	g_data.lexed_command = vec_init(sizeof(char));
	if (!g_data.lexed_command.buffer)
		exit (EXIT_FAILURE);//TODO REPLACE
	g_data.lexed_instr = vec_init(sizeof(t_instr));
	if (!g_data.lexed_instr.buffer)
		exit (EXIT_FAILURE);//TODO REPLACE
	alloc_instr();
	g_data.tmp = vec_init(sizeof(char));
	if (!g_data.tmp.buffer)
		exit (EXIT_FAILURE);//TODO REPLACE
}

/**
 * @brief Inits Data and Start the prompt
 */
int	minishell(void)
{
	char	*line_read;

	init_data();
	set_sigaction();
	line_read = readline(PROMPT_START);
	while (line_read)
	{
		interpret_line(line_read);
		add_history(line_read);
		free(line_read);
		line_read = readline(PROMPT_START);
	}
	free(line_read);
	return (1);
}

int	main()
{
	return (!minishell());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:14:02 by awillems          #+#    #+#             */
/*   Updated: 2022/06/08 14:55:09 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

int	bkslh(void);
int	sglqot(void);
int	dblqot(void);
int	varsub(void);
int	whtspc(void);
int	spec_0_arg(void);
int	spec_1_arg(void);
int	spec_scndry_prompt(void);

int	get_elem(char *str)
{
	const char *spec_char[] = {
		"\\",
		"\'", "\"",
		"$",
		" ", "\t","\n", "\v","\f", "\r",
		"|", ";",
		"<", ">",
		"<<", ">>",
	};
	
	for (int i = 0; i < 14; i++){
		if (*spec_char[i] == *str)
		{
			if (i >= 12 && ft_strncmp(spec_char[i + 2], str, 2) == 0)
				return (i + 2);
			return (i);
		}
	}
	return (-1);
}

void	line_lexer(char *line)
{
	static int	(*func_link[])() = {
		bkslh,
		sglqot, dblqot,
		varsub,
		whtspc, whtspc, whtspc, whtspc, whtspc, whtspc,
		spec_0_arg, spec_0_arg,
		spec_1_arg, spec_1_arg,
		spec_scndry_prompt, spec_1_arg,
	};

	int i = 0;
	while (line[i])
	{
		printf("[%d]\t\'%c\'\n", i, line[i]);
		if (get_elem(&line[i]) != -1)
			i += func_link[get_elem(&line[i])]();
		else
			i++;
	}
}

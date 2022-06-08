/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:14:02 by awillems          #+#    #+#             */
/*   Updated: 2022/06/08 14:31:11 by awillems         ###   ########.fr       */
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
	
	for (int j = 0; j < 14; j++){
		if (*spec_char[j] == *str)
		{
			if (ft_strncmp(spec_char[j + 2], str, 2) == 0)
				return (j + 2);
			return (j);
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
		printf("[%d]\t\'%c\'\t=>\t%d\n", i, line[i], get_elem(&line[i]));
		if (get_elem(&line[i]) != -1)
			func_link[get_elem(&line[i])]();
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:14:02 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 09:41:55 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	print_instr(size_t len);

static	void	init_opt(t_lexer_opt *opt)
{
	opt->new_instr = 1;
	opt->new_arg = 0;
	opt->nb_instr = 0;
}

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
	t_lexer_opt	opt;

	init_opt(&opt);
	int i = 0;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	while (line[i])
	{
		printf("[%d]\t\'%c\'\n", i, line[i]);
		if (get_elem(&line[i]) != -1)
			i += func_link[get_elem(&line[i])](line, i, &opt);
		else
			i += dflt_char(line, i, &opt);
	}
	vec_print(get_line());
	print_instr(opt.nb_instr);
}

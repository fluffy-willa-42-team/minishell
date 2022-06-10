/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:14:02 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 12:57:40 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	print_instr(size_t len);

static	void	init_opt(t_lexer_opt *opt)
{
	opt->new_instr = 1;
	opt->new_arg = 0;
	opt->nb_instr = 0;
	opt->index_line = 0;
	opt->index_instr = 0;
}

/**

 IND | CHAR | FUNCTION
-----0------0----------
   0 |    \ | bkslh
   1 |    ' | sglqot
   2 |    " | dblqot
   3 | $VAR | varsub
   4 |  ' ' | whtspc
   5 |   \t | whtspc
   6 |   \n | whtspc
   7 |   \v | whtspc
   8 |   \f | whtspc
   9 |   \r | whtspc
  10 |    | | spec_0_arg
  11 |    ; | spec_0_arg
  12 |    < | spec_1_arg
  13 |    > | spec_1_arg
  14 |   << | spec_scndry_prompt
  15 |   >> | spec_1_arg
-----0------0----------
   DEFAULT  | dflt_char
*/

lexer_param	lexer_param_func(char *str)
{
	const char			*spec_char[] = {
		"\\", "\'", "\"", "$", " ", "\t", "\n", "\v", "\f", "\r", "|", ";", "<",
		">", "<<", ">>",
	};
	const lexer_param	func_link[] = {
		bkslh, sglqot, dblqot, varsub, whtspc, whtspc, whtspc, whtspc, whtspc,
		whtspc, spec_0_arg, spec_0_arg, spec_1_arg, spec_1_arg,
		spec_scndry_prompt, spec_1_arg,
	};
	int					i;

	while (i < 14)
	{
		if (*spec_char[i] == *str)
		{
			if (i >= 12 && ft_strncmp(spec_char[i + 2], str, 2) == 0)
				return (func_link[i + 2]);
			return (func_link[i]);
		}
		i++;
	}
	return (dflt_char);
}

void	line_lexer(char *line)
{
	t_lexer_opt	opt;
	int			i;

	init_opt(&opt);
	i = 0;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	while (line[i])
	{
		printf("[%d]\t\'%c\'\n", i, line[i]);
		i += lexer_param_func(&line[i])(line, i, &opt);
	}
	vec_print(get_line());
	print_instr(opt.nb_instr);
}

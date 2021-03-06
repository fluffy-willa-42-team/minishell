/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:14:02 by awillems          #+#    #+#             */
/*   Updated: 2022/07/03 14:33:41 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_parser.h"
#include <errno.h>
#include <string.h>
#include "vec_utils.h"
#include "lib_str.h"
#include "lib_is_check.h"

void	add_cmd_path(t_parser_opt *opt, int index);

static void	init_opt(t_parser_opt *opt)
{
	opt->nb_instr = 0;
	opt->index_line = 0;
	opt->index_instr = -1;
	opt->option = 1;
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
  14 |   << | spec_1_arg
  15 |   >> | spec_1_arg
-----0------0----------
   DEFAULT  | dflt_char
*/

t_parser_param	parser_param_func(char *str)
{
	const char				*spec_char[] = {
		"\\", "\'", "\"", "$", " ", "\t", "\n", "\v", "\f", "\r", "|", ";", "<",
		">", "<<", ">>",
	};
	const t_parser_param	func_link[] = {
		bkslh, sglqot, dblqot, varsub, whtspc, whtspc, whtspc, whtspc, whtspc,
		whtspc, spec_0_arg, spec_0_arg, spec_1_arg, spec_1_arg,	spec_1_arg,
		spec_1_arg,
	};
	int						i;

	i = 0;
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

/**
 * @brief int => char *
 */
int	change_int_to_ptr(int *input, char **output)
{
	if (!(0 <= *input && *input <= (int) get_line()->alloc_len))
		return (0);
	*output = get_line()->buffer + *input;
	return (1);
}

int	line_parser(char *line)
{
	size_t			*x;
	t_parser_opt	opt;
	size_t			i;

	x = &g_data.parsing_index;
	init_opt(&opt);
	while (line[*x] && ft_is_whitespace(line[*x]))
		(*x)++;
	while (line[*x] && line[*x] != ';' && !(opt.option & ALLOC_FAIL))
		*x += parser_param_func(&line[*x])(line, *x, &opt);
	if (!line[*x])
		*x = 0;
	if (opt.option & ALLOC_FAIL)
		return (msh_return(-1, errno, strerror(errno), __FUNCTION__));
	i = -1;
	while (++i < get_instr_list()->len)
		if (!vec_cast(get_instr_arg(i), sizeof(char *), change_int_to_ptr))
			return (msh_return(-1, errno, strerror(errno), __FUNCTION__));
	if (opt.option & PARSING_ERROR)
		return (msh_return(-1, 258, ERR_PARSE, __FUNCTION__));
	return (opt.nb_instr);
}

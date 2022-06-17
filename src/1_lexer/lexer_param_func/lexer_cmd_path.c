/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:48:49 by awillems          #+#    #+#             */
/*   Updated: 2022/06/17 10:33:18 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_lexer.h"

void	add_cmd_path(t_lexer_opt *opt, int index_instr)
{
	const int	index = *((int *) vec_get(get_instr_arg(index_instr), 0));
	const char	*path = "/path/";

	if (opt->index_instr != -1 && opt->nb_instr - opt->index_instr > 1)
		return ;
	printf("VAR FINISHED => %s%s\n", path, vec_get_str(get_line(), index));
}
// printf("%lu + %lu | %d\n", opt->index_line, ft_strlen(path), index);
// vec_insert(get_line(), DEFAULT, index, path);
// opt->index_line += ft_strlen(path);
// printf("%lu | %d\n", opt->index_line, index);
// int *x = vec_get(get_instr_arg(opt->nb_instr - 1), -1);
// *x += ft_strlen(path);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:40:18 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 17:41:19 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

void	print_instr(size_t len, int type);

void	parser_debug(int nb_instr)
{
	print_debug_sep("BUFFER");
	if (DEBUG_PRINT)
		vec_print(get_line());
	print_debug_sep("STRUCTURE");
	print_instr(nb_instr, -1);
}

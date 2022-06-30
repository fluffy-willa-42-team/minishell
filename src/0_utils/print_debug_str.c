/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:03:34 by awillems          #+#    #+#             */
/*   Updated: 2022/06/30 12:56:26 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_debug.h"
#include "stdio.h"

void	print_debug_sep(char *str)
{
	if (DEBUG_PRINT)
		printf("%s0=====-----	%s	-----=====0%s\n", "\e[0;36m", str, "\e[0m");
}

void	print_debug(char *str)
{
	if (DEBUG_PRINT)
		printf("%s%s%s\n", "\e[0;33m", str, "\e[0m");
}

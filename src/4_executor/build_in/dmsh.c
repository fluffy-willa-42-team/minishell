/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:34:48 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/03 10:10:39 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_debug.h"
#include "env_utils.h"

int	dmsh(char **args)//XXX debug tools for msh
{
	(void)args;
	print_debug_sep("DEBUG DEBUG DEBUG");
	print_debug_sep("DEBUG DEBUG DEBUG");
	print_debug_sep("env");
	print_env("", "=", "");
	print_debug_sep("env s");
	print_env_s();
	print_debug_sep("DEBUG DEBUG DEBUG");
	print_debug_sep("DEBUG DEBUG DEBUG");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:34:48 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/05 11:09:26 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_debug.h"
#include "env_utils.h"

/**
 * Custom build-in debugger.
 */
void	dmsh(char **args)
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
}

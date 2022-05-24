/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:16:20 by awillems          #+#    #+#             */
/*   Updated: 2022/05/24 14:50:41 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "msh_prompt.h"

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	//DEBUG TODO REMOVE
	setbuf(stdout, NULL);
	
	msh_prompt();
	//TODO make custom exit function that free stuff befor quit
	return (0);
}

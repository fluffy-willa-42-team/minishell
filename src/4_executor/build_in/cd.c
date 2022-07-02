/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:06:29 by awillems          #+#    #+#             */
/*   Updated: 2022/07/02 11:11:21 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//CHECK IF EXIST
//CHECK IF FOLDER
//CHANGE DIR
//CHANGE PATH
int	msh_cd(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		printf("%s\n", args[i]);
	}
	return (1);
}

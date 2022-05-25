/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:05:48 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/25 12:01:59 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "msh_debug.h"

/**
 * @brief Free an adress and set to `NULL`.
 * 
 * @param ptr Adress to free
 */
void	msh_free(void *ptr)
{
	if (MSH_DEBUG)
		printf("free [%p]\n", ptr);
	free(ptr);
	ptr = NULL;
}

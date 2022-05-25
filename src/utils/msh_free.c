/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:05:48 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/25 11:07:40 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Free an adress and set to `NULL`.
 * 
 * @param ptr Adress to free
 */
void	msh_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

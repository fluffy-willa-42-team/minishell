/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_special_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:12:41 by awillems          #+#    #+#             */
/*   Updated: 2022/06/03 11:29:55 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_special_elem(char *elem)
{
	static char	*spec_str[6] = {"|", ";", ">>", ">", "<<", "<"};
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(elem, spec_str[i]) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}

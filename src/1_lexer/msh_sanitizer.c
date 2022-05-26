/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_sanitizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:04:23 by awillems          #+#    #+#             */
/*   Updated: 2022/05/26 11:49:11 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector_lib.h"

/**
 * @brief [Internal] Check if the charachter in the line at the index i is a
 * whitespace that has to be deleted.
 */
static int	check_sanitize(const char *line, int i, int len, int has_char)
{
	return (!(ft_is_whitespace(line[i])
			&& ((i < len - 1 && ft_is_whitespace(line[i + 1]))
			|| (i == len - 1) || (!has_char))));
}

/**
 * @brief Removes all unecessary whitespaces.
 */
void	san_whitespace(t_vec *res, const char *line)
{
	int len = ft_strlen(line);
	int i = 0;
	int has_char = 0;

	while (i < len)
	{
		if (check_sanitize(line, i , len, has_char))
		{
			if (ft_is_whitespace(line[i]))
				vec_fill(res, FIXED_LEN, " ", 1);
			else
				vec_fill(res, FIXED_LEN, &line[i], 1);
			has_char = 1;
		}
		i++;
	}
}

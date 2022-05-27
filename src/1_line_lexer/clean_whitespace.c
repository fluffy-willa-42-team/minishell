/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:04:55 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 12:09:23 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "vec_utils.h"

int	is_whitespace_good(t_vec *res, int i)
{
	(void) res;
	(void) i;
	return (1);
}

void	clean_whitespace(t_vec *res)
{
	const int	len = ft_strlen(res->buffer);
	int			i;
	int			is_in_quotes;

	is_in_quotes = 0;
	i = 0;
	while (i < len)
	{
		if (ft_is_whitespace(vec_get_char(res, i))
				&& is_whitespace_good(res, i))
			vec_fill(res, FIXED_LEN, " ", 1);
		else
		{
			if (vec_get_char(res, i) == '\'' || vec_get_char(res, i) == '\"')
				is_in_quotes = !is_in_quotes;
			vec_fill(res, FIXED_LEN, vec_get_str(res, i), 1);
		}
		i++;
	}
	int new_len = ft_strlen(res->buffer + len);
	ft_memmove(res->buffer, res->buffer + len, new_len);
	ft_bzero(res->buffer + new_len, res->len - new_len);
}

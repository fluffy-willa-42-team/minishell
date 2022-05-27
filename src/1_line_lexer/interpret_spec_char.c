/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_spec_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:52:49 by awillems          #+#    #+#             */
/*   Updated: 2022/05/27 10:56:05 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Will replace delete every '\' that is not followed by a char in
 * to_place_manual.
 */
void	interpret_spec_char(t_vec *res, const char *line)
{
	const char	*to_place_manual = "\\";
	int			i;
	int			is_in_quotes;

	is_in_quotes = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\\' && !is_in_quotes)
		{
			if (line[i + 1] && ft_strrchr(to_place_manual, line[i + 1]) != 0)
			{
				vec_fill(res, FIXED_LEN, &line[i + 1], 1);
				i++;
			}
		}
		else
		{
			if (line[i] == '\'')
				is_in_quotes = !is_in_quotes;
			vec_fill(res, FIXED_LEN, &line[i], 1);
		}
		i++;
	}
}

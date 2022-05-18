/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:55:33 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/17 15:24:42 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_vector line = init_vector_str("Lorem ipsum dolor sit amet. Rem commodi earum");
	char *line_read = readline("[test] ");

	print_vector(line);
	insert_vector(&line, line_read, 10);
}

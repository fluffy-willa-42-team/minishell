/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:51:25 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/30 16:42:56 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "env_utils.h"

t_vec	*env(char **test)
{
	if (!test)
		return (NULL);
	test++;
	while (*test)
	{
		printf("env set [%s]\n", *test);
		env_set("TEST", *test, 1);//TODO ENV mettre seulement le nom de la variable.
		updt_env();
		print_env();
		test++;
	}
	return NULL;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:38 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/27 14:55:37 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

void	vec_new_env_s(char	*str)
{
	t_env	new_env;

	if (!str)
	{
		printf ("vec_new_env_s NULL str\n");
		exit(1);//TODO
	}
	// else
		// printf("Try add [%s]\n", str);
	new_env.content = vec_init(sizeof(char));
	if (!vec_fill(&new_env.content, DEFAULT, str))
	{
		printf("vec_new_env_s fail to write new env");
		exit (1);//TODO
	}
	// vec_print(&new_env.content);//TODO
	new_env.env_len = 0;//TODO strlen while `c != '='`
	while (*str && *str != '=')
	{
		new_env.env_len++;
		str++;
	}
	new_env.token = 0;//TODO   hash
	if (!vec_add(&g_data.env_s, &new_env))
	{
		printf("vec_new_env_s fail to add new env");
		exit (1);//TODO
	}
}

t_env	*vec_get_t_env(t_vec *vec, int index)
{
	return ((t_env *)vec_get(vec, index));
}

char	*vec_get_env_str(t_vec *vec, int index)
{
	return ((char *)vec_get_t_env(vec, index)->content.buffer);
}

void	init_env(char **env)
{
	int	index;

	index = 0;
	g_data.env_s = vec_init(sizeof(t_env));

	while (env[index])
	{
		vec_new_env_s(env[index]);
		index++;
	}
	for (size_t i = 0; i < g_data.env_s.content_len; i++)
	{
		char *tmp = vec_get_env_str(&g_data.env_s, i);
		if (tmp)
			printf("%2lu]{%2d}[%s]\n", i, vec_get_t_env(&g_data.env_s, i)->env_len, tmp);
		else
			printf("FUK!\n");
	}
	vec_pop(&g_data.env_s, 3);

}
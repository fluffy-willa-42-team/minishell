/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:38 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/27 16:15:10 by mahadad          ###   ########.fr       */
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

void	print_env(void)
{
	for (size_t i = 0; i < 10; i++)
	{
		char *tmp = vec_get_env_str(&g_data.env_s, i);
		if (tmp)
			printf("%2lu]{%2d}[%s]\n", i, vec_get_t_env(&g_data.env_s, i)->env_len, tmp);
		else
			printf("FUK!\n");
	}
	printf("\n");
}

/**
 * @brief Will destroy the env vector and pop.
 *        WARN! If the content dont exist will segfault !! //TODO check 
 */
t_vec	*env_pop(t_vec *vec, int index)
{
	vec_destroy(&vec_get_t_env(vec, index)->content);
	return (vec_pop(vec, index));
}

/**
 * @brief Will erase all content and set `token` and `env_len` to `0`.
 */
void	env_unset(int index)
{
	t_env *env;

	env = vec_get_t_env(&g_data.env_s, index);
	vec_delete(&env->content);
	env->env_len = 0;
	env->token = 0;
}

/**
 * @brief If the `new_elem` exit will erase the content. If `new_elem` dont exist will
 *        find a enmpty env_t or create a new one.
 */
// t_vec	*env_set(`new_elem`)

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
	print_env();
	env_pop(&g_data.env_s, 3);
	env_unset(2);
	env_unset(3);
	print_env();
}
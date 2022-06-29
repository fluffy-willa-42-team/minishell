/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:38 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/29 16:56:11 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "env_utils.h"
#include "lib_str.h"

/**
 * [LOCAL]
 * Convert unix env structure to t_env structure.
 * First fill the vec with `str`, find the var name length and hash it.
 * 
 * EXEMPLE
 *    unix -> TEST=UwU Be Gentle
 *   t_env -> {
 *              token:   6384537573UL,
 *              env_len: 4,
 *              t_vec { buff->"TEST=UwU Be Gentle" },
 *            }
 */
static void	sysenv_to_t_env(char *str)
{
	t_env	new_env;

	if (!str)
	{
		printf ("sysenv_to_t_env NULL str\n");
		exit(1);//TODO
	}
	new_env.content = vec_init(sizeof(char));
	if (!vec_fill(&new_env.content, DEFAULT, str))
	{
		printf("sysenv_to_t_env fail to write new env");
		exit (1);//TODO
	}
	new_env.env_len = 0;
	while (str[new_env.env_len] && str[new_env.env_len] != '=')
		new_env.env_len++;
	new_env.token = djb2_hash(str, new_env.env_len);
	if (!vec_add(&g_data.env_s, &new_env))
	{
		printf("sysenv_to_t_env fail to add new env");
		exit (1);//TODO
	}
}

void	print_env(void)
{
	setbuf(stdout, NULL);
	for (size_t i = 0; i < g_data.env_s.content_len; i++)
	{
		char *tmp = vec_get_env_str(i);
		if (tmp)
		{
			printf("[%2lu]{%2d}(%-20lu) ", i, vec_get_t_env(i)->env_len, vec_get_t_env(i)->token);
			int tmp_len = ft_strlen(tmp);
			int write_len = tmp_len;
			if (tmp_len > 64)
				write_len = 62;
			write(1, tmp, write_len);
			if (tmp_len > 64)
				write(1, "..", 2);
			write(1, "\n", 1);
		}
		else
			printf("FUK!\n");
	}
	printf("\n");
}

void	init_env(char **env)
{
	int	index;

	index = 0;
	g_data.env_s = vec_init(sizeof(t_env));
	while (env[index])
	{
		sysenv_to_t_env(env[index]);
		index++;
	}
	printf("\e[0;36m0=====-----	T_ENV	-----=====0\n\e[0m");
	print_env();(void)getchar();
	env_set("UwU", "Ima new, be gentle with me!", 0);
	print_env();(void)getchar();
	env_set("UwU", "Try to kill", 0);
	print_env();(void)getchar();
	env_set("UwU", "AAAAAAAAAAAA w-why you try to kill me!", 1);
	print_env();(void)getchar();
	env_unset(env_get("UwU"));
	print_env();(void)getchar();
	env_set("OwO", "I take ur place buddy!", 0);
	print_env();(void)getchar();
}

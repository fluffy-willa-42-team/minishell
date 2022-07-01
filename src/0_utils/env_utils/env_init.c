/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:38 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/30 16:45:40 by mahadad          ###   ########.fr       */
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
	new_env.content = (t_vec) vec_init(char);
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

void	print_env_s(void)//TODO DEBUG 
{
	setbuf(stdout, NULL);
	for (size_t i = 0; i < g_data.env_s.len; i++)
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

t_vec	*updt_env(void)
{
	size_t i;

	vec_delete(&g_data.env);
	i = 0;
	while (i < g_data.env_s.len)
	{
		if (vec_get_t_env(i)->token)
			vec_add(&g_data.env, &vec_get_t_env(i)->content.buffer);
		i++;
	}
	return (NULL);
}

void	init_env(char **env)
{
	int	index;

	index = 0;
	while (env[index])
	{
		sysenv_to_t_env(env[index]);
		index++;
	}
	print_debug_sep("T_ENV");
	updt_env();
	if (DEBUG_PRINT)
		print_env();
}

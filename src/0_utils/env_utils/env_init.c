/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:38 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/29 14:37:16 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include "env_utils.h"
#include "lib_str.h"

/**
 * this algorithm (k=33) was first reported by dan bernstein many years
 * ago in comp.lang.c. another version of this algorithm
 * (now favored by bernstein) uses
 * xor: hash(i) = hash(i - 1) * 33 ^ str[i]; the magic of number 33
 * (why it works better than many other constants, prime or not) has
 * never been adequately explained.
 * 
 * NOTE : if strlen(`str`) == 0 will return 5381;
 * 
 * SOURCE : https://web.archive.org/web/20220610182409/http://www.cse.yorku.ca/~oz/hash.html
 */
unsigned long	djb2_hash(char *str, int len)
{
	unsigned long hash = 5381;
	int	index;

	index = 0;
	while (str[index] && index < len)
	{
		hash = ((hash << 5) + hash) + (int)str[index];
		index++;
	}
	return (hash);
}

/**
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
void	sysenv_to_t_env(char *str)
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

/**
 * Add new t_env structure.
 * 
 * WARN if there a `=` in the `name` will return error.
 * 
 * EXEMPLE
 *   new("TEST", "UwU Be Gentle");
 *   t_env -> {
 *              token:   6384537573UL,
 *              env_len: 4,
 *              t_vec { buff->"TEST=UwU Be Gentle" },
 *            }
 */
void	vec_add_new_env(char *name, char *content)
{
	t_env	new_env;

	if (!name || ft_strchr(name, '='))
	{
		printf ("vec_add_new_env NULL name OR `=`find in name\n");
		exit(1);//TODO
	}
	new_env.content = vec_init(sizeof(char));
	if (!vec_fill(&new_env.content, MULTI, 3, name, "=", content))
	{
		printf("vec_add_new_env fail to write new env");
		exit (1);//TODO
	}
	new_env.env_len = 0;
	while (name[new_env.env_len] && name[new_env.env_len] != '=')
		new_env.env_len++;
	new_env.token = djb2_hash(name, new_env.env_len);
	if (!vec_add(&g_data.env_s, &new_env))
	{
		printf("vec_add_new_env fail to add new env");
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

/**
 * @brief Will destroy the env vector and pop.
 *        WARN! If the content dont exist will segfault !! //TODO check 
 */
t_vec	*env_pop(t_vec *vec, int index)
{
	vec_destroy(&vec_get_t_env(index)->content);
	return (vec_pop(vec, index));
}

/**
 * @brief Will erase all content and set `token` and `env_len` to `0`.
 */
void	env_unset(int index)
{
	t_env *env;

	env = vec_get_t_env(index);
	vec_delete(&env->content);
	env->env_len = 0;
	env->token = 0;
}

/**
 * Will hash name and try to find in the hash table.
 * WARN : If name = `""` the hash will be 5381
 */
t_env	*env_get(char *name)
{
	unsigned long	hash;
	int				i;

	i = 0;
	while (name[i])
		i++;
	hash = djb2_hash(name, i);
	i = 0;
	while (i < (int)g_data.env_s.content_len && vec_get_t_env(i)->token != hash)
		i++;
	if (i == (int)g_data.env_s.content_len)
		return (NULL);
	return (vec_get_t_env(i));
}

/**
 *  Will hash the `name` and concatenate `name`=`value`
 *  Same as :
 *        int setenv(const char *name, const char *value, int overwrite);
 * 
 *        The setenv() function adds the variable name to the environment
 *        with the value value, if name does not already exist.  If name
 *        does exist in the environment, then its value is changed to value
 *        if overwrite is nonzero; if overwrite is zero, then the value of
 *        name is not changed (and setenv() returns a success status).
 * 
 * RETURN VALUE
 *        setenv() and unsetenv() functions return zero on success, or -1
 *        on error, with errno set to indicate the error.
 * ERRORS
 *        EINVAL name is NULL, points to a string of length 0, or contains
 *               an '=' character.
 *        ENOMEM Insufficient memory to add a new variable to the
 *               environment.
 * 
 */
// t_vec	*env_set(char *name, char *value, int overwrite)
// {
// 	t_env	*env;
// 	int		i;

// 	env = env_get(name);
// 	if (!env)
// 	{
// 		i = 0;
// 		while (i < (int)g_data.env_s.content_len && vec_get_t_env(i)->token != 0UL)
// 			i++;
// 		if (i == (int)g_data.env_s.content_len)
// 		return (NULL);
// 	}
	
// }

void	init_env(char **env)
{
	int	index;

	index = 0;
	g_data.env_s = vec_init(sizeof(t_env));
	g_data.env_s.rate = 1;
	printf("INFO g_data [%lu][%lu]\n", g_data.env_s.size, g_data.env_s.len);

	while (env[index])
	{
		sysenv_to_t_env(env[index]);
		index++;
	}
	printf("\e[0;36m0=====-----	T_ENV	-----=====0\n\e[0m");
	print_env();
	env_pop(&g_data.env_s, 3);
	env_unset(2);
	printf("\e[0;36m0=====-----	POP UNSET TEST	-----=====0\n\e[0m");
	print_env();
	printf("\e[0;36m0=====-----	GET TEST	-----=====0\n\e[0m");
	if (env_get("PWD"))
		printf("%s\n", (char *)(env_get("PWD")->content.buffer));
	else
		printf("NULL!\n");
	printf("\e[0;36m0=====-----	ADD TEST	-----=====0\n\e[0m");
	vec_add_new_env("UWU", "123");
	vec_add_new_env("UWU4", "123");
	vec_add_new_env("UWU44", "123");
	vec_add_new_env("UWU444", "123");
	vec_add_new_env("UWU4443", "123");
	vec_add_new_env("UWU44433", "123");
	vec_add_new_env("UWU444333", "123");
	vec_add_new_env("UWU4443332", "123");
	vec_add_new_env("UWU44433322", "123");
	vec_add_new_env("UWU444333222", "123");
	vec_add_new_env("UWU4443332222", "123");
	vec_add_new_env("UWU4443332222s", "123");
	vec_add_new_env("UWU444333222s", "123");
	vec_add_new_env("UWU44433322s", "123");
	vec_add_new_env("UWU4443332s", "123");
	vec_add_new_env("UWU444333s", "123");
	vec_add_new_env("UWU44433s", "123");
	vec_add_new_env("UWU4443s", "123");
	vec_add_new_env("UWU444s", "123");
	vec_add_new_env("UWU44s", "123");
	vec_add_new_env("UWU4s", "123");
	vec_add_new_env("UWUs", "123");
	vec_add_new_env("UWs", "123");
	vec_add_new_env("UW", "123");
	vec_add_new_env("U", "123");
	if (env_get("UWU"))
		printf("%s\n", (char *)(env_get("UWU")->content.buffer));
	else
		printf("NULL!\n");
	print_env();
}
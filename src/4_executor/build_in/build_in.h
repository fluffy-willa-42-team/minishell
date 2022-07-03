/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:18:27 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/03 11:11:03 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_H
# define BUILD_IN_H

# define NB_BUILD_IN 8

typedef int	(*t_build_in)();

int	dummy(char **env);
int	env(char **env);
int	export(char **env);
int	msh_cd(char **args);
int	msh_pwd(char **args);
int	msh_echo(char **args);
int	msh_exit_cmd(char **args);
int	msh_unset(char **args);
int	dmsh(char **args);//XXX debug tools for msh

#endif /* BUILD_IN_H */

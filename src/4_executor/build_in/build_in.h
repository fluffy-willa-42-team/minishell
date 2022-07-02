/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:18:27 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/02 11:17:28 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_H
# define BUILD_IN_H

typedef int	(*t_build_in)();

int	dummy(char **env);
int	env(char **env);
int	export(char **env);
int	msh_cd(char **args);
int	msh_pwd(char **args);
int	msh_echo(char **args);
int	msh_exit_cmd(char **args);
int	msh_unset(char **args);

#endif /* BUILD_IN_H */

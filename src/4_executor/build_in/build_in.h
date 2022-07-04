/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:18:27 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/03 17:01:04 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_H
# define BUILD_IN_H

# define NB_BUILD_IN 8

typedef void	(*t_build_in)();

void	msh_env(char **args, int fds[2]);
void	msh_export(char **args, int fds[2]);
void	msh_cd(char **args, int fds[2]);
void	msh_pwd(char **args, int fds[2]);
void	msh_echo(char **args, int fds[2]);
void	msh_exit_cmd(char **args, int fds[2]);
void	msh_unset(char **args, int fds[2]);
void	dmsh(char **args, int fds[2]);//XXX debug tools for msh

#endif /* BUILD_IN_H */

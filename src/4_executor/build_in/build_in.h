/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:18:27 by mahadad           #+#    #+#             */
/*   Updated: 2022/07/05 11:11:53 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_H
# define BUILD_IN_H

# define NB_BUILD_IN 8

typedef void	(*t_build_in)();

void	msh_env(char **args);
void	msh_export(char **args);
void	msh_cd(char **args);
void	msh_pwd(char **args);
void	msh_echo(char **args);
void	msh_exit_cmd(char **args);
void	msh_unset(char **args);
void	dmsh(char **args);
#endif /* BUILD_IN_H */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:45:29 by mahadad           #+#    #+#             */
/*   Updated: 2022/05/19 17:10:33 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_PROMPT_H
# define MSH_PROMPT_H

# include <stdio.h>
# include <unistd.h>
 #include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <errno.h>

# define PROMPT_TXT "UwU $> "

void prompt (void);

# endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:40:30 by awillems          #+#    #+#             */
/*   Updated: 2022/05/26 11:42:48 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_EXIT_H
# define MSH_EXIT_H

/**
 * @brief Error handler macro.
 * [0][0][0]
 *  ^  ^
 *  |  |
 *  |  |-: If true -> `EXIT_FAILURE`. If false `EXIT_SUCCESS`.
 *  |-: If fisrt bit `true`  -> we exit the prog.
 *  |-: If fisrt bit `false` -> print error message.
 */
typedef enum s_msh_exit
{
	MSH_D_DEBUG   = 0b000,
	MSH_D_SUCCESS = 0b001,
	MSH_D_ERROR   = 0b010,
	MSH_E_DEBUG   = 0b100,
	MSH_E_SUCCESS = 0b101,
	MSH_E_ERROR   = 0b110
}			t_msh_exit;

#endif /* MSH_EXIT_H */

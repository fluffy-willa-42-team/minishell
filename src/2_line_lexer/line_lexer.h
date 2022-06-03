/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lexer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:09:31 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/03 09:22:21 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_LEXER_H
# define LINE_LEXER_H

int	inredir(int line_index, t_vec *line, t_vec *instr);
int	outredir(int line_index, t_vec *line, t_vec *instr);
int	ppe(int line_index, t_vec *line, t_vec *instr);

#endif /* LINE_LEXER_H */

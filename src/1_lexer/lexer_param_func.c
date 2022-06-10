/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_param_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:22:55 by awillems          #+#    #+#             */
/*   Updated: 2022/06/10 08:46:30 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_instr(t_vec* instr, size_t index, int type, char *arg);
void	add_arg(size_t index, char *arg);

int bkslh(char *line, int index)
{
	(void) line;
	(void) index;
	printf("\\\\\n");
	return (1);
}

int sglqot(char *line, int index)
{
	(void) line;
	(void) index;
	printf("\'\'\n");
	return (1);
}

int dblqot(char *line, int index)
{
	(void) line;
	(void) index;
	printf("\"\"\n");
	return (1);
}

int varsub(char *line, int index)
{
	(void) line;
	(void) index;
	printf("$$\n");
	return (1);
}

int whtspc(char *line, int index)
{
	(void) line;
	(void) index;
	printf("whooooooooosh\n");
	return (1);
}

int spec_0_arg(char *line, int index)
{
	(void) line;
	(void) index;
	printf("spec 0\n");
	return (1);
}

int spec_1_arg(char *line, int index)
{
	(void) line;
	(void) index;
	printf("spec 1\n");
	return (1);
}

int spec_scndry_prompt(char *line, int index)
{
	(void) line;
	(void) index;
	printf("spec scndry prmpt\n");
	return (1);
}

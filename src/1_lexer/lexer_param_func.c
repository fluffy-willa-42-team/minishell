/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_param_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awillems <awillems@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:22:55 by awillems          #+#    #+#             */
/*   Updated: 2022/06/08 14:37:06 by awillems         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int bkslh(void)
{
	printf("\\\\\n");
	return (1);
}

int sglqot(void)
{
	printf("\'\'\n");
	return (1);
}

int dblqot(void)
{
	printf("\"\"\n");
	return (1);
}

int varsub(void)
{
	printf("$$\n");
	return (1);
}

int whtspc(void)
{
	printf("whooooooooosh\n");
	return (1);
}

int spec_0_arg(void)
{
	printf("spec 0\n");
	return (1);
}

int spec_1_arg(void)
{
	printf("spec 1\n");
	return (1);
}

int spec_scndry_prompt(void)
{
	printf("spec scndry prmpt\n");
	return (1);
}

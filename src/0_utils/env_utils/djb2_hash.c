/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djb2_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:00:20 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/30 10:59:44 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
 * SOURCE :
 *   web.archive.org/web/20220610182409/http://www.cse.yorku.ca/~oz/hash.html
 */
unsigned long	djb2_hash(char *str, int len)
{
	unsigned long	hash;
	int				index;

	index = 0;
	hash = 5381;
	while (str[index] && index < len)
	{
		hash = ((hash << 5) + hash) + (int)str[index];
		index++;
	}
	return (hash);
}

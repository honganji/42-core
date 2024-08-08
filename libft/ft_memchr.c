/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:28:50 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/10 16:54:09 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	chr;

	p = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n--)
	{
		if (*p == chr)
			return (p);
		p++;
	}
	return (NULL);
}

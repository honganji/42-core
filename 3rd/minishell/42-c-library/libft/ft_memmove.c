/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:29:08 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/10 17:53:29 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	if (!dst && !src)
		return (dst);
	if (dst <= src)
	{
		while (len--)
			*ptr_dst++ = *ptr_src++;
	}
	else
	{
		ptr_dst += len - 1;
		ptr_src += len - 1;
		while (len--)
			*ptr_dst-- = *ptr_src--;
	}
	return (dst);
}

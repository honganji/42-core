/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:35:34 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/10 17:01:25 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	count;
	size_t	dest_size;
	int		src_size;

	count = 0;
	src_size = get_strlen(src);
	dest_size = get_strlen(dest);
	while (dest[count])
		count++;
	if (dest_size < size)
	{
		while (count < size - 1 && src[count - dest_size])
		{
			dest[count] = src[count - dest_size];
			count++;
		}
		dest[count] = '\0';
	}
	if (dest_size >= size)
		return (src_size + size);
	else
		return (dest_size + src_size);
	return (0);
}

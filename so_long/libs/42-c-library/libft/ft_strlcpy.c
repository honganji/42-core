/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:35:39 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/10 17:01:20 by ytoshihi         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	int	count;

	count = get_strlen(src);
	if (size == 0)
		return (count);
	while (size-- > 1 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (count);
}

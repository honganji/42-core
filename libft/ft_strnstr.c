/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:36:10 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/10 17:50:10 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static int	check_if_same(const char *str1, const char *str2, size_t size)
{
	while (size--)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;

	needle_size = get_strlen(needle);
	if (!needle_size)
		return ((char *)haystack);
	while (*haystack && len-- >= needle_size)
	{
		if (check_if_same(haystack, needle, needle_size))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:57:24 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/24 10:34:06 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str++ == c)
			return (--str);
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dst;

	len = ft_strlen(src) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
	{
		free(s1);
		return (NULL);
	}
	ft_strcpy(dst, s1);
	ft_strcpy(dst + ft_strlen(s1), s2);
	free(s1);
	return (dst);
}

char	*ft_substr(char *src, int i)
{
	char	*dst;
	int		count;

	dst = (char *)malloc((i + 1) * sizeof(char));
	if (!dst)
		return (free(src), NULL);
	count = -1;
	while (++count < i)
		dst[count] = src[count];
	dst[count] = '\0';
	free(src);
	return (dst);
}

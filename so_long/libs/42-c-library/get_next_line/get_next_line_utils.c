/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:29:12 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/14 20:43:46 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_gnl_calloc(size_t num, size_t size)
{
	void	*p;
	int		tmp;

	tmp = num * size;
	if (num && size && (tmp / size != num))
		return (NULL);
	p = malloc(tmp);
	if (!p)
		return (NULL);
	ft_gnl_bzero(p, tmp);
	return (p);
}

void	ft_gnl_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}

int	ft_gnl_strchr(const char *s, int c)
{
	char	*str;
	char	chr;

	str = (char *)s;
	chr = (char)c;
	while (*str)
	{
		if (*str == chr)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		count;

	str = (char *)malloc((ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1)
			* sizeof(char));
	if (!str)
		return (NULL);
	count = 0;
	while (*s1)
		str[count++] = *s1++;
	while (*s2)
		str[count++] = *s2++;
	str[count] = '\0';
	return (str);
}

size_t	ft_gnl_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

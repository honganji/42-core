/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:36:44 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/11 17:57:07 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_strlen(char const *s)
{
	unsigned int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	count;

	count = 0;
	if (!*s || !len || get_strlen(s) < start)
		return (ft_strdup(""));
	if (get_strlen(s) - start < len)
		len = get_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (count < len && s[start + count])
	{
		str[count] = s[start + count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

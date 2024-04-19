/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:35:13 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/11 17:43:42 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_strlen(char const *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*value;
	int		count;

	length = get_strlen(s1);
	value = (char *)malloc((length + 1) * sizeof(char));
	if (!value)
		return (NULL);
	count = 0;
	while (s1[count])
	{
		value[count] = s1[count];
		count++;
	}
	value[count] = '\0';
	return (value);
}

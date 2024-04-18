/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:36:20 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/10 16:33:32 by ytoshihi         ###   ########.fr       */
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

char	*ft_strrchr(const char *str, int c)
{
	int		count;
	char	chr;

	count = get_strlen(str);
	chr = (char)c;
	while (count >= 0)
	{
		if (str[count] == chr)
			return ((char *)&str[count]);
		count--;
	}
	return (NULL);
}

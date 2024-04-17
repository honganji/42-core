/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:35:08 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/10 16:58:44 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	chr;

	str = (char *)s;
	chr = (char)c;
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	if (*str == chr)
		return (str);
	return (NULL);
}

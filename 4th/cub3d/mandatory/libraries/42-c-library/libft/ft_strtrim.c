/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:36:25 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/10 19:43:30 by ytoshihi         ###   ########.fr       */
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

char	*ft_strtrim(char *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	start = 0;
	end = get_strlen(s1) - 1;
	if (!*s1)
		return (ft_strdup(""));
	if (!*set)
		return (ft_strdup(s1));
	while (start <= end && s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end >= start && s1[end] && ft_strchr(set, s1[end]))
		end--;
	str = (char *)malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}

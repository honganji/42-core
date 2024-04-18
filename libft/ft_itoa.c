/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:20 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/08 11:43:22 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_value(char *value, int n, int count)
{
	if (n < 0)
	{
		value[0] = '-';
		n *= -1;
	}
	count--;
	while (n)
	{
		value[count--] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		count;
	int		tmp;
	char	*value;

	count = 0;
	tmp = n;
	value = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp)
	{
		tmp /= 10;
		count++;
	}
	if (n < 0)
		count++;
	value = (char *)malloc((count + 1) * sizeof(char));
	if (!value)
		return (NULL);
	value[count] = '\0';
	get_value(value, n, count);
	return (value);
}

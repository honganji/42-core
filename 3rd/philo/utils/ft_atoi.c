/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:28:26 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/02 11:57:11 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief atoi function
 * 
 * @param str string that should be converted to long type
 * 
 * @return long
*/
long	ft_atoi(const char *str)
{
	long	sign;
	long	ab_num;

	sign = 1;
	ab_num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ab_num = 10 * ab_num + (*str - '0');
		str++;
	}
	return (ab_num * sign);
}

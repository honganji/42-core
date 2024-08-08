/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:36:55 by yuji              #+#    #+#             */
/*   Updated: 2024/06/09 17:59:17 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Check if the numbers are more than 0
 * 
 * @param args input argument that are converted as int type
 * 
 * @return void
*/
int	check_num(int args[5])
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (i != 4 && args[i] <= 0)
		{
			error();
			return (0);
		}
		if (i != 0 && i != 4 && (args[i] > 0 && args[i] < 60))
		{
			write(2, "One of the time is less than 60 ms\n", 36);
			return (0);
		}
	}
	return (1);
}

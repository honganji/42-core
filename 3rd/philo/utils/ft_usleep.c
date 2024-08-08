/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:26:43 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/27 11:00:10 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief Stop program for specified time(milliseconds)
 * To make it more accurate, it repeat usleep function multiple times.
 * 
 * @param sleep_time time to stop the program
 * 
 * @return void
*/
void	ft_usleep(size_t sleep_time)
{
	size_t	const_time;
	size_t	start;

	const_time = 500;
	start = ft_get_current_time();
	while (ft_get_current_time() - start < sleep_time)
		usleep(const_time);
}

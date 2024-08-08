/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_current_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:20:05 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/11 15:29:34 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief Get current time as millisecond unit
 * 
 * @return void
*/
size_t	ft_get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		error();
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/**
 * @brief get the current timestamp
 * 
 * @param data data hold all info
 * 
 * @return void
*/
size_t	stamp(t_data *data)
{
	size_t	time_stamp;

	pthread_mutex_lock(&data->mutex_time);
	time_stamp = ft_get_current_time() - data->start_time;
	pthread_mutex_unlock(&data->mutex_time);
	return (time_stamp);
}

/**
 * @brief get the difference between last time a philosopher ate
 * and current time.
 * 
 * @param data data hold all info
 * @param i index of a philosopher
 * 
 * @return void
*/
int	get_diff(t_data *data, int i)
{
	int	diff;

	pthread_mutex_lock(&data->mutex_last_time);
	diff = (int)(ft_get_current_time() - data->philos[i].last_time_eat);
	pthread_mutex_unlock(&data->mutex_last_time);
	return (diff);
}

/**
 * @brief Set the time for last time a philosopher ate
 * 
 * @param data data hold all info
 * 
 * @return void
*/
void	set_last_time(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex_last_time);
	data->philos[i].last_time_eat = ft_get_current_time();
	pthread_mutex_unlock(&data->mutex_last_time);
}

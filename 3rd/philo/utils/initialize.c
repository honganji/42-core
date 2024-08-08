/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 09:50:18 by yuji              #+#    #+#             */
/*   Updated: 2024/06/11 15:46:48 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief initialize all values in data structure
 * 
 * @param data holds whole data
 * @param args array of int that holds input parameters
 * 
 * @return void
*/
void	initialize(t_data *data, int *args)
{
	int		i;

	i = -1;
	data->num_of_philos = args[0];
	data->time_to_die = args[1];
	data->time_to_eat = args[2];
	data->time_to_sleep = args[3];
	data->index = 0;
	data->is_finish = 0;
	pthread_mutex_init(&(data->mutex_print), NULL);
	pthread_mutex_init(&(data->mutex_start), NULL);
	pthread_mutex_init(&(data->mutex_time), NULL);
	pthread_mutex_init(&(data->mutex_last_time), NULL);
	pthread_mutex_init(&(data->mutex_meal), NULL);
	pthread_mutex_init(&(data->mutex_index), NULL);
	pthread_mutex_init(&(data->mutex_thread), NULL);
	pthread_mutex_init(&(data->mutex_isfinish), NULL);
	while (++i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].count_meal = args[4];
		data->philos[i].last_time_eat = ft_get_current_time();
		pthread_mutex_init(&data->philos[i].mutex_fork, NULL);
	}
	data->philos[i].id = 0;
}

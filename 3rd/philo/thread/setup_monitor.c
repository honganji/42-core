/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:48:41 by yuji              #+#    #+#             */
/*   Updated: 2024/06/11 15:54:39 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

/**
 * @brief Join whole thread and finish
 * 
 * @param data data hold all info
 * 
 * @return void
*/
static void	join_all_philo(t_data *data)
{
	int	i;

	i = -1;
	while (data->philos[++i].id)
		pthread_join(data->philos[i].thread, NULL);
}

/**
 * @brief Check if one philosopher is dead
 * 
 * @param data data hold all info
 * 
 * @return void
*/
static void	check_is_dead(t_data *data)
{
	int	i;
	int	diff;

	i = -1;
	while (data->philos[++i].id)
	{
		diff = get_diff(data, i);
		if ((int)(data->time_to_die - diff) <= 0)
		{
			pthread_mutex_lock(&data->mutex_print);
			printf("%zu %d died\n", stamp(data), data->philos[i].id);
			pthread_mutex_unlock(&data->mutex_print);
			pthread_mutex_lock(&data->mutex_isfinish);
			data->is_finish = 1;
			pthread_mutex_unlock(&data->mutex_isfinish);
			return ;
		}
	}
}

/**
 * @brief Check if all philosopher ate as much meal as specified
 * 
 * @param data data hold all info
 * 
 * @return void
*/
static void	check_full(t_data *data)
{
	int	i;
	int	count_meal;

	i = -1;
	while (data->philos[++i].id)
	{
		pthread_mutex_lock(&data->mutex_meal);
		count_meal = data->philos[i].count_meal;
		pthread_mutex_unlock(&data->mutex_meal);
		if (count_meal)
			return ;
	}
	pthread_mutex_lock(&data->mutex_isfinish);
	data->is_finish = 1;
	pthread_mutex_unlock(&data->mutex_isfinish);
}

/**
 * @brief Detect if the program should be finished or not
 * 
 * @param arg argument that holds data
 * 
 * @return void
*/
static void	*detect_finish(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (data->is_finish == -1 || !data->is_finish)
	{
		check_is_dead(data);
		check_full(data);
	}
	join_all_philo(data);
	return (NULL);
}

/**
 * @brief setup monitor
 * 
 * @param data data hold all info
 * 
 * @return void
*/
void	setup_monitor(t_data *data)
{
	pthread_create(&data->thread, NULL, detect_finish, (void *)data);
}

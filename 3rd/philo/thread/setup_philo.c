/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:46:33 by yuji              #+#    #+#             */
/*   Updated: 2024/06/11 17:26:45 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

/**
 * @brief Print message for each case: eating, sleeping, and thinking
 * 
 * @param data data hold all info
 * @param type indicate which type
 * @param i index of the philosopher
 * 
 * @return void
*/
static void	print_message(t_data *data, int type, int i)
{
	size_t	time;
	int		is_finish;

	time = stamp(data);
	pthread_mutex_lock(&data->mutex_isfinish);
	is_finish = data->is_finish;
	pthread_mutex_unlock(&data->mutex_isfinish);
	if (!is_finish)
	{
		pthread_mutex_lock(&data->mutex_print);
		if (type == 0)
			printf("%zu %d has taken a fork\n%zu %d has taken"
				" a fork\n%zu %d is eating\n", time,
				data->philos[i].id, time, data->philos[i].id,
				time, data->philos[i].id);
		else if (type == 1)
			printf("%zu %d is sleeping\n", time, data->philos[i].id);
		else if (type == 2)
			printf("%zu %d is thinking\n", time, data->philos[i].id);
		pthread_mutex_unlock(&data->mutex_print);
	}
}

/**
 * @brief Set routine(eat, sleep, and think) for a philosopher
 * 
 * @param data data hold all info
 * @param i index of the philosopher
 * @param next index of the next philosopher
 * 
 * @return void
*/
static int	set_routine(t_data *data, int i, int next)
{
	if (i == next)
		return (0);
	pthread_mutex_lock(&data->philos[i].mutex_fork);
	pthread_mutex_lock(&data->philos[next].mutex_fork);
	print_message(data, 0, i);
	set_last_time(data, i);
	ft_usleep(data->time_to_eat);
	if (data->philos[i].count_meal > 0)
	{
		pthread_mutex_lock(&data->mutex_meal);
		data->philos[i].count_meal--;
		pthread_mutex_unlock(&data->mutex_meal);
	}
	pthread_mutex_unlock(&data->philos[i].mutex_fork);
	pthread_mutex_unlock(&data->philos[next].mutex_fork);
	print_message(data, 1, i);
	ft_usleep(data->time_to_sleep);
	print_message(data, 2, i);
	if (data->is_finish)
		return (0);
	return (1);
}

static void	setup_index(t_data *data, int *i, int *next)
{
	pthread_mutex_lock(&data->mutex_index);
	while (*i < data->index)
		(*i)++;
	if (!data->philos[*i + 1].id)
		*next = 0;
	else
		*next = *i + 1;
	data->index++;
	pthread_mutex_unlock(&data->mutex_index);
}

/**
 * @brief Set routine(eat, sleep, and think) for each philosopher
 * 
 * @param arg holds data
 * 
 * @return void
*/
static void	*start_activity(void *args)
{
	t_data	*data;
	int		next;
	int		i;

	data = (t_data *)args;
	i = 0;
	setup_index(data, &i, &next);
	pthread_mutex_lock(&data->mutex_start);
	pthread_mutex_unlock(&data->mutex_start);
	if (data->num_of_philos != 1 && data->philos[i].id % 2 == 1)
	{
		print_message(data, 2, i);
		ft_usleep(data->time_to_eat / 2);
	}
	set_last_time(data, i);
	while (1)
		if (!set_routine(data, i, next))
			return (NULL);
}

/**
 * @brief Set up for all philosophers
 * 
 * @param data data hold all info
 * 
 * @return void
*/
void	setup_philo(t_data *data)
{
	int			i;

	i = -1;
	pthread_mutex_lock(&data->mutex_start);
	while (data->philos[++i].id)
	{
		pthread_create(&data->philos[i].thread, NULL,
			start_activity, (void *)data);
	}
	data->start_time = ft_get_current_time();
	pthread_mutex_unlock(&data->mutex_start);
}

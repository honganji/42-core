/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:21:50 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/11 15:46:37 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "utils/utils.h"
# include "thread/thread.h"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				count_meal;
	size_t			last_time_eat;
	pthread_mutex_t	mutex_fork;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				is_finish;
	int				index;
	int				num_of_philos;
	size_t			start_time;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_start;
	pthread_mutex_t	mutex_time;
	pthread_mutex_t	mutex_last_time;
	pthread_mutex_t	mutex_meal;
	pthread_mutex_t	mutex_index;
	pthread_mutex_t	mutex_thread;
	pthread_mutex_t	mutex_isfinish;
	pthread_t		thread;
}	t_data;

#endif
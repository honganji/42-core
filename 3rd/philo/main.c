/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:21:37 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/11 17:25:27 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Check and store input into array of int.
 * Then initialize data.
 * After that, setup routines(eat, sleep, and think) for each philosopher.
 * Also setup function to monitor if all philosopher ate as much meals as
 * specified or one of them is dead
 * 
 * @param argc the number of arguments
 * @param argv array of arguments
 * 
 * @return int
*/
int	main(int argc, char **argv)
{
	int		args[5];
	t_data	*data;

	if (!store_input(argc, argv, args) || !check_num(args))
		return (1);
	if (args[4] == 0)
		return (0);
	data = (t_data *)malloc(1 * sizeof(t_data));
	data->philos = (t_philo *)malloc((args[0] + 1) * sizeof(t_philo));
	initialize(data, args);
	setup_philo(data);
	setup_monitor(data);
	pthread_join(data->thread, NULL);
	clean_data(data);
	return (0);
}

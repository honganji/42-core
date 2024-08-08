/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:00:26 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/11 15:38:24 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Destroy thread and mutext
 * 
 * @param data whole data
 * 
 * @return void
*/
static void	reset_mutex(t_data *data)
{
	int		i;

	i = -1;
	while (data->philos[++i].id)
		pthread_mutex_destroy(&data->philos[i].mutex_fork);
}

/**
 * @brief Clean up whole data
 * 
 * @param data whole data
 * 
 * @return void
*/
void	clean_data(t_data *data)
{
	reset_mutex(data);
	free(data->philos);
	free(data);
}

/**
 * @brief Clean up array of string
 * 
 * @param arr the array of string
 * 
 * @return void
*/
void	free_str_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

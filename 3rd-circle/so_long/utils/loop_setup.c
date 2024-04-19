/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:55:32 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/16 14:16:08 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	loop_func(void *param)
{
	t_data	*data;
	char	position;

	data = (t_data *)param;
	position = data->map[data->position.y][data->position.x];
	if (data->count == data->col_sum && position == 'E')
		update_image(data, 'G', data->size.x / 4, data->size.y / 4);
}

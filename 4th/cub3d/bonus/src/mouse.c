/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:48:56 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/26 17:25:57 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static void	condition(t_data *data, double xdelta)
{
	double	old_x;
	double	rotation;

	rotation = 0.3;
	if (xdelta < WINDOW_WIDTH / 2)
	{
		rotation = rotation * (WINDOW_WIDTH / 2 - xdelta) / WINDOW_WIDTH;
		old_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-rotation)
			- data->plane_y * sin(-rotation);
		data->plane_y = old_x * sin(-rotation) + data->plane_y * cos(-rotation);
		data->angle -= rotation;
	}
	else
	{
		rotation = rotation * (xdelta - WINDOW_WIDTH / 2) / WINDOW_WIDTH;
		old_x = data->plane_x;
		data->plane_x = data->plane_x * cos(rotation)
			- data->plane_y * sin(rotation);
		data->plane_y = old_x * sin(rotation) + data->plane_y * cos(rotation);
		data->angle += rotation;
	}
}

void	set_cursor(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)ydelta;
	condition(data, xdelta);
	mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	data->old_xdelta = xdelta;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:32:57 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/29 16:42:44 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static void	display_map(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->map, 0, 0))
		clean(data);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	data->map = mlx_new_image(data->mlx, data->col + 1, data->ln + 1);
	if (!data->map)
		clean(data);
	y = -1;
	while (++y < data->ln)
	{
		x = -1;
		while (++x < data->col)
		{
			if (data->scene->map[y][x] == '1')
				mlx_put_pixel(data->map, x, y, 0xFFFFFFFF);
			else if (data->scene->map[y][x] != ' ')
				mlx_put_pixel(data->map, x, y, 0xdbdbd040);
			if (data->scene->map[y][x] == 'D')
				mlx_put_pixel(data->map, x, y, 0xFF6347FF);
			else if (data->scene->map[y][x] == 'O')
				mlx_put_pixel(data->map, x, y, 0xB0FC38FF);
		}
	}
	mlx_resize_image(data->map, (data->col + 1)
		* data->side, (data->ln + 1) * data->side);
	display_map(data);
}

void	draw_player(t_data *data)
{
	data->circle = mlx_new_image(data->mlx, 10, 10);
	if (!data->circle)
		clean(data);
	draw_circle(data->circle, 10, 0x00DD00FF);
	data->direction = mlx_new_image(data->mlx, 5, 5);
	if (!data->direction)
		clean(data);
	draw_circle(data->direction, 5, 0xFFFFFFFF);
	if (mlx_image_to_window(data->mlx, data->direction, 100, 100))
		clean(data);
	if (mlx_image_to_window(data->mlx, data->circle, 97, 97))
		clean(data);
}

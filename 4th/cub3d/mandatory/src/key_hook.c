/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:56:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/27 16:01:10 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static void	wasd_key_hook(t_data *data, int *step)
{
	double	diff;

	diff = 0;
	if (data->x && mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		*step = data->side / 6;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S)
		|| mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_D))
			diff = M_PI / 2;
		else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
			diff = M_PI;
		else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
			diff = M_PI * 3 / 2;
		if (!check_wall(data, *step, diff))
			return ;
		data->y += *step * sin(data->angle + diff);
		data->x += *step * cos(data->angle + diff);
	}
}

static void	lr_key_hook(t_data *data, int step, double old_x, double rotation)
{
	if (data->y < data->side)
		data->y += step;
	if (data->x < data->side)
		data->x += step;
	if (data->y > data->side * (data->ln - 1))
		data->y -= step;
	if (data->x > data->side * (data->col - 1))
		data->x -= step;
	data->angle = fmod(data->angle, 2 * M_PI);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		old_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-rotation)
			- data->plane_y * sin(-rotation);
		data->plane_y = old_x * sin(-rotation) + data->plane_y * cos(-rotation);
		data->angle -= rotation;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		old_x = data->plane_x;
		data->plane_x = data->plane_x * cos(rotation)
			- data->plane_y * sin(rotation);
		data->plane_y = old_x * sin(rotation) + data->plane_y * cos(rotation);
		data->angle += rotation;
	}
}

void	key_hook(void *param)
{
	t_data	*data;
	double	old_x;
	double	rotation;
	int		step;

	data = (t_data *)param;
	old_x = 0;
	rotation = 0.05;
	step = data->side / 12;
	wasd_key_hook(data, &step);
	lr_key_hook(data, step, old_x, rotation);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		exit(EXIT_SUCCESS);
}

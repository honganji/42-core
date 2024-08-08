/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkijewsk <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:46:57 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/28 20:30:35 by mkijewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	check_door(t_param_ray *param, t_data *data)
{
	if (param->box_dist_x < 3 && param->box_dist_y < 3
		&& param->screen > -0.25f && param->screen < 0.25f)
	{
		if (param->map[data->box_y][data->box_x] == 'O'
			&& mlx_is_key_down(data->mlx, MLX_KEY_E) && !data->cooldown)
		{
			param->map[data->box_y][data->box_x] = 'D';
			data->cooldown = 15;
			mlx_resize_image(data->map, data->col + 1, data->ln + 1);
			mlx_put_pixel(data->map, data->box_x, data->box_y, 0xFF6347FF);
			mlx_resize_image(data->map, (data->col + 1)
				* data->side, (data->ln + 1) * data->side);
		}
		else if (param->map[data->box_y][data->box_x] == 'D'
			&& mlx_is_key_down(data->mlx, MLX_KEY_E) && !data->cooldown)
		{
			param->map[data->box_y][data->box_x] = 'O';
			data->cooldown = 15;
			mlx_resize_image(data->map, data->col + 1, data->ln + 1);
			mlx_put_pixel(data->map, data->box_x, data->box_y, 0xB0FC38FF);
			mlx_resize_image(data->map, (data->col + 1)
				* data->side, (data->ln + 1) * data->side);
		}
	}
}

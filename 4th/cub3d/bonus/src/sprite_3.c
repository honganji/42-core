/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:21:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/21 13:45:41 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	manage_sprites(t_data *data)
{
	if (data->sprite_count < 10)
		data->sprite_count++;
	else
	{
		data->sprite_count = 0;
		if (data->sprite_index == 9)
			data->sprite_index = 5;
		data->sprite_index++;
	}
}

void	cal_box(t_param_ray *param, t_data *data)
{
	if (param->box_dist_x < param->box_dist_y)
	{
		param->box_dist_x += param->delta_x;
		data->box_x += param->step_x;
		param->side = 0;
	}
	else
	{
		param->box_dist_y += param->delta_y;
		data->box_y += param->step_y;
		param->side = 1;
	}
}

unsigned int	get_texture_color(t_param_ray *param, t_data *data, int y_r)
{
	unsigned int	color;

	color = reverse_bits(data->pixel_array[data->sprite_index]
		[(int)((double)(param->x - data->sprite_init_pos)
				/ data->sprite_width
				* data->textures[data->sprite_index]->width)
			+ data->textures[data->sprite_index]->width * (y_r)]);
	return (color);
}

void	cal_width(t_param_ray *param, t_data *data,
	int old_box_x, int old_box_y)
{
	data->sprite_width = 0;
	while (data->is_sprite && param->x < 10 * WINDOW_WIDTH)
	{
		initialize_ray_sprite(param, data);
		initialize_step_sprite(param, data);
		count_width(param, data);
		if (param->side == 0)
			param->wall_dist = param->box_dist_x - param->delta_x;
		else
			param->wall_dist = param->box_dist_y - param->delta_y;
		if (data->box_x < 0 || data->box_x >= data->col
			|| data->box_y < 0 || data->box_y >= data->ln
			|| data->box_x != old_box_x || data->box_y != old_box_y)
			break ;
		param->x++;
		store_max_height(param, data);
	}
}

void	render_sp_line(t_param_ray *param, t_data *data, int tmp_box_x,
	int tmp_box_y)
{
	int	tmp_x;

	if (!data->sprite_width && data->is_sprite)
	{
		tmp_x = param->x;
		get_sprite_width(data, param);
		param->x = tmp_x;
	}
	data->box_x = tmp_box_x;
	data->box_y = tmp_box_y;
	if (data->is_sprite && (data->old_box_x != data->box_x
			|| data->old_box_y != data->box_y))
	{
		tmp_x = param->x;
		get_sprite_width(data, param);
		param->x = tmp_x;
	}
	data->box_x = tmp_box_x;
	data->box_y = tmp_box_y;
	if (param->x >= 0)
		render_sprite(param, data);
	else
		param->x++;
}

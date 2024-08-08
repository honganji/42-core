/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:26:56 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/21 13:47:33 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	initialize_x(t_param_ray *param, t_data *data)
{
	while (1)
	{
		initialize_ray_sprite(param, data);
		initialize_step_sprite(param, data);
		get_box_size_sprite(param, data);
		if (data->box_x < 0 || data->box_x >= data->col || data->box_y < 0
			|| data->box_y >= data->ln
			|| param->map[data->box_y][data->box_x] != '2'
			|| param->x < -10 * WINDOW_WIDTH)
			break ;
		if (param->map[data->box_y][data->box_x] == '2')
			param->x--;
	}
}

void	get_sprite_size(t_param_ray *param, t_data *data, int *tmp_x)
{
	int	tmp_box_x;
	int	tmp_box_y;

	while (param->x < WINDOW_WIDTH)
	{
		data->old_box_x = data->box_x;
		data->old_box_y = data->box_y;
		initialize_ray_sprite(param, data);
		initialize_step_sprite(param, data);
		get_box_size_sprite(param, data);
		tmp_box_x = data->box_x;
		tmp_box_y = data->box_y;
		if (data->box_x < 0 || data->box_x >= data->col
			|| data->box_y < 0 || data->box_y >= data->ln
			|| param->map[data->box_y][data->box_x] == '1'
			|| param->map[data->box_y][data->box_x] == 'D')
		{
			data->sprite_width = 0;
			param->x++;
			continue ;
		}
		(void)tmp_x;
		render_sp_line(param, data, tmp_box_x, tmp_box_y);
	}
}

void	count_width(t_param_ray *param, t_data *data)
{
	while (1)
	{
		cal_box(param, data);
		if (data->box_x < 0 || data->box_x >= data->col
			|| data->box_y < 0 || data->box_y >= data->ln)
			break ;
		if (param->map[data->box_y][data->box_x] == '1'
			|| param->map[data->box_y][data->box_x] == 'D')
		{
			data->is_sprite = 0;
			break ;
		}
		if (param->map[data->box_y][data->box_x] == '2')
		{
			data->is_sprite = 1;
			data->sprite_width++;
			break ;
		}
	}
}

void	store_max_height(t_param_ray *param, t_data *data)
{
	if (data->max_height < WINDOW_HEIGHT / param->wall_dist)
		data->max_height = WINDOW_HEIGHT / param->wall_dist;
}

void	draw_sprite(t_param_ray *param, t_data *data)
{
	int				start;
	int				end;
	int				y_r;
	int				y;
	unsigned int	color;

	start = -data->max_height / 2 + WINDOW_HEIGHT / 2;
	end = data->max_height / 2 + WINDOW_HEIGHT / 2;
	y = -1;
	if (param->side == 0 || param->side == 1)
		param->wall_pos = 1 - param->wall_pos;
	while (++y < WINDOW_HEIGHT)
	{
		if (y > start && y < end && (y > 200 || param->x > 200))
		{
			y_r = (y - (WINDOW_HEIGHT - data->max_height) / 2)
				* data->textures[data->sprite_index]->height
				/ data->max_height;
			color = get_texture_color(param, data, y_r);
			if (color != 0x000000FF)
				mlx_put_pixel(data->frame, param->x, y, color);
		}
	}
}

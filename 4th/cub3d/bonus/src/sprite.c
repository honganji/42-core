/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:20:36 by yuji              #+#    #+#             */
/*   Updated: 2024/07/21 13:47:42 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	initialize_ray_sprite(t_param_ray *param, t_data *data)
{
	param->pos_x = data->x / (double) data->side;
	param->pos_y = data->y / (double) data->side;
	data->box_x = (int) param->pos_x;
	data->box_y = (int) param->pos_y;
	param->screen = param->x / (double) WINDOW_WIDTH * 2 - 1;
	param->ray_x = cos(data->angle) + data->plane_x * param->screen;
	param->ray_y = sin(data->angle) + data->plane_y * param->screen;
	if (param->ray_x == 0)
		param->delta_x = (double) 1e30;
	else
		param->delta_x = fabs(1 / param->ray_x);
	if (param->ray_y == 0)
		param->delta_y = (double) 1e30;
	else
		param->delta_y = fabs(1 / param->ray_y);
}

void	initialize_step_sprite(t_param_ray *param, t_data *data)
{
	if (param->ray_x < 0)
	{
		param->step_x = -1;
		param->box_dist_x = (param->pos_x - data->box_x) * param->delta_x;
	}
	else
	{
		param->step_x = 1;
		param->box_dist_x = (data->box_x + 1.0 - param->pos_x)
			* param->delta_x;
	}
	if (param->ray_y < 0)
	{
		param->step_y = -1;
		param->box_dist_y = (param->pos_y - data->box_y) * param->delta_y;
	}
	else
	{
		param->step_y = 1;
		param->box_dist_y = (data->box_y + 1.0 - param->pos_y)
			* param->delta_y;
	}
}

void	get_box_size_sprite(t_param_ray *param, t_data *data)
{
	while (1)
	{
		cal_box(param, data);
		if (data->box_x < 0 || data->box_x >= data->col || data->box_y < 0
			|| data->box_y >= data->ln)
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
			break ;
		}
	}
}

void	render_sprite(t_param_ray *param, t_data *data)
{
	if (param->side == 0)
		param->wall_dist = param->box_dist_x - param->delta_x;
	else
		param->wall_dist = param->box_dist_y - param->delta_y;
	if (param->side == 0)
		param->wall_pos = fmod(param->pos_y + param->wall_dist
				* param->ray_y, 1);
	else
		param->wall_pos = fmod(param->pos_x + param->wall_dist
				* param->ray_x, 1);
	if (param->side == 1 && param->step_y == 1)
		param->side = 0;
	else if (param->side == 0 && param->step_x == -1)
		param->side = 1;
	else if (param->side == 1 && param->step_y == -1)
		param->side = 2;
	else if (param->side == 0 && param->step_x == 1)
		param->side = 3;
	draw_sprite(param, data);
	param->x++;
}

void	get_sprite_width(t_data *data, t_param_ray *param)
{
	int	old_box_x;
	int	old_box_y;

	data->sprite_init_pos = param->x;
	data->max_height = 0;
	old_box_x = data->box_x;
	old_box_y = data->box_y;
	cal_width(param, data, old_box_x, old_box_y);
}

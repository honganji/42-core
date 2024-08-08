/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkijewsk <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:20:36 by yuji              #+#    #+#             */
/*   Updated: 2024/07/28 20:26:12 by mkijewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	initialize_ray(t_param_ray *param, t_data *data)
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

void	initialize_step(t_param_ray *param, t_data *data)
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

static void	set_box(t_param_ray *param, t_data *data)
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

void	get_box_size(t_param_ray *param, t_data *data)
{
	param->door_hit = 0;
	while (1)
	{
		set_box(param, data);
		if (data->box_x < 0 || data->box_x >= data->col || data->box_y < 0
			|| data->box_y >= data->ln)
			break ;
		if (param->map[data->box_y][data->box_x] == 'D')
		{
			param->door_hit = 1;
			check_door(param, data);
			break ;
		}
		check_door(param, data);
		if (param->map[data->box_y][data->box_x] == '1'
			|| param->map[data->box_y][data->box_x] == 'D')
			break ;
	}
}

void	render(t_param_ray *param, t_data *data)
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
	if (param->door_hit == 1)
		param->side = 4;
	draw_vertical_line(&(t_param_vl){param->x, WINDOW_HEIGHT
		/ param->wall_dist, data, param->side, param->wall_pos});
	param->x++;
}

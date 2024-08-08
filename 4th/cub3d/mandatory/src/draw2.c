/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:13:32 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/08 17:56:13 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	draw_map(void *param)
{
	mlx_image_t	*square;
	t_data		*data;
	int			i;
	int			j;

	i = -1;
	data = param;
	square = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	draw_sq(square, data->side);
	while (data->scene->map[++i])
	{
		j = 0;
		while (data->scene->map[i][j])
		{
			if (ft_strchr("NESW", data->scene->map[i][j]))
			{
				data->y = i * data->side + data->side / 2;
				data->x = j * data->side + data->side / 2;
				data->angle = initial_direction(data->scene->map[i][j]);
				data->plane_x = -0.66 * sin(data->angle);
				data->plane_y = 0.66 * cos(data->angle);
			}
			j++;
		}
	}
}

static	void	draw_image(t_param_vl *param, int y)
{
	int			start;
	int			end;
	int			y_r;

	start = -param->length / 2 + WINDOW_HEIGHT / 2;
	end = param->length / 2 + WINDOW_HEIGHT / 2;
	if (param->side == 0 || param->side == 1)
		param->wall_pos = 1 - param->wall_pos;
	while (y < WINDOW_HEIGHT)
	{
		if (y > start && y < end)
		{
			y_r = (y - (WINDOW_HEIGHT - param->length) / 2)
				* param->data->textures[param->side]->height / param->length;
			mlx_put_pixel(param->data->frame, param->x, y,
				reverse_bits(param->data->pixel_array[param->side]
				[(int)(param->wall_pos
						* param->data->textures[param->side]->width)
					+ param->data->textures[param->side]->width * (y_r)]));
		}
		y++;
	}
}

void	draw_vertical_line(t_param_vl *param)
{
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
		mlx_put_pixel(param->data->frame, param->x, y++, param->data->scene->c);
	while (y < WINDOW_HEIGHT)
		mlx_put_pixel(param->data->frame, param->x, y++, param->data->scene->f);
	y = 0;
	draw_image(param, y);
}

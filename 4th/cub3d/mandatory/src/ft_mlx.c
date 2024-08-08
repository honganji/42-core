/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:50:24 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/24 15:42:37 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	ray(void *value)
{
	t_data		*data;
	t_param_ray	*param;

	param = ft_calloc(1, sizeof(t_param_ray));
	data = value;
	param->map = data->scene->map;
	param->x = 0;
	while (param->x < WINDOW_WIDTH)
	{
		initialize_ray(param, data);
		initialize_step(param, data);
		get_box_size(param, data);
		render(param, data);
	}
	free(param);
}

void	ft_init_mlx(t_data *data)
{
	store_nesw_path(data);
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Shooting GAME", true);
	data->ln = map_height(data->scene->map);
	data->col = count_rows(data->scene->map);
	if (data->ln < data->col)
		data->side = WINDOW_WIDTH / data->col;
	else
		data->side = WINDOW_HEIGHT / data->ln;
	if (data->side == 0)
		data->side = 12;
	draw_map(data);
	data->frame = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (mlx_image_to_window(data->mlx, data->frame, 0, 0))
		clean(data);
	mlx_loop_hook(data->mlx, key_hook, data);
	mlx_loop_hook(data->mlx, ray, data);
}

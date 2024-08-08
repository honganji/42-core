/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:50:24 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/24 15:47:29 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static void	ray(void *value)
{
	t_data		*data;
	t_param_ray	*param;

	param = ft_calloc(1, sizeof(t_param_ray));
	data = value;
	param->map = data->scene->map;
	param->x = 0;
	param->c = '1';
	if (data->cooldown > 0)
		data->cooldown--;
	while (param->x < WINDOW_WIDTH)
	{
		initialize_ray(param, data);
		initialize_step(param, data);
		get_box_size(param, data);
		render(param, data);
	}
	free(param);
}

static void	sprite(void *value)
{
	t_data		*data;
	t_param_ray	*param;
	int			tmp_x;

	param = ft_calloc(1, sizeof(t_param_ray));
	data = value;
	param->map = data->scene->map;
	param->x = 0;
	param->c = '2';
	data->sprite_len = 0;
	data->is_sprite = 0;
	data->sprite_width = 0;
	data->last_sprite_width = WINDOW_WIDTH;
	tmp_x = param->x;
	initialize_x(param, data);
	get_sprite_size(param, data, &tmp_x);
	manage_sprites(data);
	free(param);
}

void	ft_init_mlx(t_data *data)
{
	store_textures(data);
	data->sprite_index = 5;
	data->sprite_count = 0;
	data->old_xdelta = 0;
	data->old_ydelta = 0;
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Shooting GAME", true);
	if (!data->mlx)
		clean(data);
	data->ln = map_height(data->scene->map);
	data->col = count_rows(data->scene->map);
	data->side = 20;
	initial_position(data);
	data->frame = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->frame)
		clean(data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	draw_map(data);
	draw_player(data);
	if (mlx_image_to_window(data->mlx, data->frame, 0, 0) == 1)
		clean(data);
	mlx_loop_hook(data->mlx, key_hook, data);
	data->cooldown = 15;
	mlx_loop_hook(data->mlx, ray, data);
	mlx_loop_hook(data->mlx, sprite, data);
	mlx_cursor_hook(data->mlx, &set_cursor, data);
}

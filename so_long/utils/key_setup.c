/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:50:08 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/16 14:21:24 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->count != data->col_sum
		|| data->map[data->position.y][data->position.x] != 'E')
	{
		if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			&& keydata.action == MLX_PRESS)
			move(param, 0, -1);
		if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			&& keydata.action == MLX_PRESS)
			move(param, -1, 0);
		if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			&& keydata.action == MLX_PRESS)
			move(param, 0, 1);
		if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			&& keydata.action == MLX_PRESS)
			move(param, 1, 0);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		free_data(data);
}

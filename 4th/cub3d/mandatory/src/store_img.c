/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:41:33 by yuji              #+#    #+#             */
/*   Updated: 2024/07/24 18:17:25 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static void	get_input_path(t_data *data, t_param_img *param, char direction)
{
	if (direction == 'E')
	{
		param->index = 1;
		param->path = data->scene->ea;
	}
	else if (direction == 'S')
	{
		param->index = 2;
		param->path = data->scene->so;
	}
	else if (direction == 'W')
	{
		param->index = 3;
		param->path = data->scene->we;
	}
	else
	{
		param->index = 0;
		param->path = data->scene->no;
	}
}

static void	store_img_path(t_data *data, t_param_img *param, char direction)
{
	int	fd;

	get_input_path(data, param, direction);
	fd = open(param->path, O_RDONLY);
	if (ft_strncmp(ft_strrchr(param->path, '.'), ".png", 4) || fd == -1)
	{
		data->textures[param->index]
			= mlx_load_png(param->images[param->index]);
	}
	else
		data->textures[param->index] = mlx_load_png(param->path);
	close(fd);
	if (mlx_errno)
	{
		free_scene(data->scene);
		clean_textures(data, param->index);
		exit(1);
	}
	data->pixel_array[param->index]
		= (uint32_t *)data->textures[param->index]->pixels;
}

void	store_nesw_path(t_data *data)
{
	t_param_img	*param;

	param = ft_calloc(1, sizeof(t_param_img));
	param->images[0] = IMG_NORTH;
	param->images[1] = IMG_EAST;
	param->images[2] = IMG_SOUTH;
	param->images[3] = IMG_WEST;
	store_img_path(data, param, 'N');
	store_img_path(data, param, 'E');
	store_img_path(data, param, 'S');
	store_img_path(data, param, 'W');
	free(param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:41:33 by yuji              #+#    #+#             */
/*   Updated: 2024/07/24 18:21:10 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static char	*free_strjoin(char *src, char *str)
{
	char	*dst;

	dst = ft_strjoin(src, str);
	if (!dst)
		return (NULL);
	free(src);
	return (dst);
}

static void	get_input_path(t_data *data, t_param_img *param, char direction)
{
	if (direction == 'N')
	{
		param->index = 0;
		param->path = data->scene->no;
	}
	else if (direction == 'E')
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
}

static void	store_img_texture(t_data *data, t_param_img *param, char direction)
{
	if (direction == 'D')
	{
		data->textures[4] = mlx_load_png(param->images[4]);
		data->pixel_array[4] = (uint32_t *)data->textures[4]->pixels;
		return ;
	}
	get_input_path(data, param, direction);
	param->fd = open(param->path, O_RDONLY);
	if (ft_strncmp(ft_strrchr(param->path, '.'), ".png", 4) || param->fd == -1)
	{
		data->textures[param->index]
			= mlx_load_png(param->images[param->index]);
	}
	else
		data->textures[param->index] = mlx_load_png(param->path);
	close(param->fd);
	if (mlx_errno)
	{
		free_scene(data->scene);
		clean_textures(data, param->index);
		exit(1);
	}
	data->pixel_array[param->index]
		= (uint32_t *)data->textures[param->index]->pixels;
}

void	store_sprite_textures(t_data *data)
{
	int		i;
	char	*str;
	char	*num;

	i = 0;
	str = ft_strdup(IMG_SPRITE);
	while (++i < IMG_NUM - 4)
	{
		str = free_strjoin(str, "_");
		num = ft_itoa(i);
		str = free_strjoin(str, num);
		free(num);
		str = free_strjoin(str, ".png");
		data->textures[i + 4] = mlx_load_png(str);
		data->pixel_array[i + 4]
			= (uint32_t *)data->textures[i + 4]->pixels;
		free(str);
		str = ft_strdup(IMG_SPRITE);
	}
	free(str);
}

void	store_textures(t_data *data)
{
	t_param_img	*param;

	param = ft_calloc(1, sizeof(t_param_img));
	param->images[0] = IMG_NORTH;
	param->images[1] = IMG_EAST;
	param->images[2] = IMG_SOUTH;
	param->images[3] = IMG_WEST;
	param->images[4] = IMG_DOOR;
	store_img_texture(data, param, 'N');
	store_img_texture(data, param, 'E');
	store_img_texture(data, param, 'S');
	store_img_texture(data, param, 'W');
	store_img_texture(data, param, 'D');
	store_sprite_textures(data);
	free(param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:08:05 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/19 15:58:19 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	update_image(t_data *data, char prop, int x, int y)
{
	int	img_index;

	if (prop == '0')
		img_index = 0;
	if (prop == '1')
		img_index = 1;
	if (prop == 'C')
		img_index = 2;
	if (prop == 'E')
		img_index = 3;
	if (prop == 'P')
		img_index = 4;
	if (prop == 'G')
		img_index = 5;
	if (prop != 'G')
		data->map[y][x] = prop;
	if (mlx_image_to_window(data->mlx, (data->images)[img_index], x * IMG_PIXEL,
			y * IMG_PIXEL) < 0)
		error("There is something wrong when to move");
}

void	register_images(t_data *data)
{
	int	i;

	i = 0;
	(data->textures)[0] = mlx_load_png(IMG_BG);
	(data->textures)[1] = mlx_load_png(IMG_WALL);
	(data->textures)[2] = mlx_load_png(IMG_COLLECTIBLE);
	(data->textures)[3] = mlx_load_png(IMG_EXIT);
	(data->textures)[4] = mlx_load_png(IMG_PLAYER);
	(data->textures)[5] = mlx_load_png(IMG_GOAL_MES);
	while (i < IMG_NUM)
	{
		(data->images)[i] = mlx_texture_to_image(data->mlx,
				(data->textures)[i]);
		mlx_resize_image((data->images)[i], IMG_PIXEL, IMG_PIXEL);
		i++;
	}
}

char	**copy_map(t_data *data)
{
	int		x;
	int		y;
	char	**tab;

	x = -1;
	y = -1;
	tab = ft_calloc(data->size.y, sizeof(char *));
	while (++y < data->size.y)
	{
		tab[y] = ft_calloc(data->size.x, sizeof(char));
		while (++x < data->size.x)
			tab[y][x] = data->map[y][x];
		x = -1;
	}
	return (tab);
}

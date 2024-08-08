/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:13:40 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/24 18:16:12 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	clean_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < IMG_NUM)
		mlx_delete_texture(data->textures[i]);
	free(data);
}

void	free_scene(t_scene *scene)
{
	free_arr(scene->map);
	free(scene->no);
	free(scene->ea);
	free(scene->so);
	free(scene->we);
	free(scene);
}

void	clean(t_data *data)
{
	printf("Allocation error. \n");
	free_scene(data->scene);
	clean_data(data);
	exit(1);
}

void	clean_textures(t_data *data, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		mlx_delete_texture(data->textures[i]);
	free(data);
}

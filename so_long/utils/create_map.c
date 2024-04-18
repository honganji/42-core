/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:21:19 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/18 14:06:32 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	allocate_map_helper(t_data *data)
{
	int	count_y;

	count_y = 0;
	data->map = ft_calloc(data->size.y, sizeof(char *));
	if (!data->map)
		error("The allocation for map failed...");
	while (count_y < data->size.y)
	{
		data->map[count_y] = ft_calloc(data->size.x, sizeof(char));
		if (!data->map[count_y])
		{
			while (count_y >= 0)
				free(data->map[count_y--]);
			free(data->map);
			error("The allocation for map failed...");
		}
		count_y++;
	}
}

static void	allocate_map(t_data *data, char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error("The file is not opend correctly...");
	line = get_next_line(fd);
	if (!line || !ft_strchr(line, '\n'))
		error("There should be more than 3 lines...");
	data->size.x = (int)ft_strlen(line) - 1;
	while (line)
	{
		if (data->size.y <= 1 && !ft_strchr(line, '\n'))
		{
			free(line);
			error("There should be more than 3 lines...");
		}
		free(line);
		line = get_next_line(fd);
		(data->size.y)++;
	}
	close(fd);
	free(line);
	allocate_map_helper(data);
}

static void	insert_values(t_data *data, char *map_path)
{
	int		fd;
	char	*line;
	int		count_x;
	int		count_y;

	count_x = 0;
	count_y = 0;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		while (count_x < data->size.x)
		{
			(data->map)[count_y][count_x] = line[count_x];
			count_x++;
		}
		free(line);
		line = get_next_line(fd);
		count_x = 0;
		count_y++;
	}
	free(line);
	close(fd);
}

static void	put_objects(t_data *data)
{
	int		x;
	int		y;
	char	c;

	x = -1;
	y = -1;
	while (++y < data->size.y)
	{
		while (++x < data->size.x)
		{
			c = (data->map)[y][x];
			update_image(data, '0', x, y);
			if (c != '0')
				update_image(data, c, x, y);
			if (c == 'C')
				data->col_sum++;
			if (c == 'P')
			{
				data->position.x = x;
				data->position.y = y;
			}
		}
		x = -1;
	}
}

void	create_map(t_data *data, char *map_path)
{
	int32_t	width;
	int32_t	height;

	allocate_map(data, map_path);
	insert_values(data, map_path);
	if (!check_walls(data))
	{
		free_map(data);
		error("The map is not surrounded by walls appropriately...");
	}
	if (!check_objects(data))
	{
		free_map(data);
		error("There is invalid object...");
	}
	width = data->size.x * IMG_PIXEL;
	height = data->size.y * IMG_PIXEL;
	mlx_set_window_size(data->mlx, width, height);
	mlx_resize_image((data->images)[IMG_NUM - 1], width / 2, height / 2);
	put_objects(data);
	if (!check_path(data))
	{
		free_data(data);
		error("The number of objects is wrong or there is unreachable one...");
	}
}

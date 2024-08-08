/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:27:08 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/19 16:01:11 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_walls(t_data *data)
{
	int		x;
	int		y;
	char	*col;

	x = 0;
	y = 0;
	col = data->map[y++];
	while (x < data->size.x)
	{
		if (col[x++] != '1')
			return (0);
	}
	while (y < data->size.y - 1)
	{
		col = data->map[y++];
		if (col[0] != '1' || col[data->size.x - 1] != '1')
			return (0);
	}
	col = data->map[y];
	x = 0;
	while (x < data->size.x)
		if (col[x++] != '1')
			return (0);
	return (1);
}

void	check_line_num(char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error("The file is not opend correctly...");
	line = get_next_line(fd);
	if (!line || !ft_strchr(line, '\n'))
		error("There should be more than 3 lines...");
	free(line);
	line = get_next_line(fd);
	if (!ft_strchr(line, '\n'))
		error("There should be more than 3 lines...");
	free(line);
	close(fd);
}

int	check_objects(t_data *data)
{
	t_count	count;

	count = (t_count){0, 0, 0, -1, -1};
	while (++count.y < data->size.y)
	{
		while (++count.x < data->size.x)
		{
			if (data->map[count.y][count.x] != '0'
				&& data->map[count.y][count.x] != '1'
				&& data->map[count.y][count.x] != 'P'
				&& data->map[count.y][count.x] != 'C'
				&& data->map[count.y][count.x] != 'E')
				return (0);
		}
		count.x = -1;
	}
	return (1);
}

void	flood_fill(char **tab, t_data *data, t_coord *pos, t_count *count)
{
	if (pos->x < 0 || pos->y < 0 || tab[pos->y][pos->x] == '1')
		return ;
	if (tab[pos->y][pos->x] == 'P')
		count->p++;
	if (tab[pos->y][pos->x] == 'C')
		count->c++;
	if (tab[pos->y][pos->x] == 'E')
		count->e++;
	tab[pos->y][pos->x] = '1';
	(void)data;
	flood_fill(tab, data, &(t_coord){pos->x - 1, pos->y}, count);
	flood_fill(tab, data, &(t_coord){pos->x + 1, pos->y}, count);
	flood_fill(tab, data, &(t_coord){pos->x, pos->y - 1}, count);
	flood_fill(tab, data, &(t_coord){pos->x, pos->y + 1}, count);
}

int	check_path(t_data *data)
{
	char		**tab;
	t_coord	pos;
	t_count		count;
	int			i;

	tab = copy_map(data);
	pos = data->position;
	count = (t_count){0, 0, 0, 0, 0};
	i = -1;
	flood_fill(tab, data, &pos, &count);
	while (++i < data->size.y)
		free(tab[i]);
	free(tab);
	if (count.p != 1 || count.c < 1 || count.e != 1 || count.c != data->col_sum)
		return (0);
	return (1);
}

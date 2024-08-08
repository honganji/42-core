/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:08:02 by mkijewsk          #+#    #+#             */
/*   Updated: 2024/07/20 15:45:08 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

static int	forbidden_char(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' \
			|| map[i][j] == 'S' || map[i][j] == 'W')
				count++;
			if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'N' \
				|| map[i][j] == 'E' || map[i][j] == 'S' || map[i][j] == 'W' \
				|| map[i][j] == ' ' || map[i][j] == '2' || map[i][j] == 'D'))
				return (-1);
			j++;
		}
		i++;
	}
	return (count);
}

static int	is_separated(char **arr, int lines)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		if (!arr[i][0])
		{
			j = i;
			while (j < lines)
			{
				if (arr[j][0])
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

static void	fill_spaces(char **map)
{
	int		i;
	int		j;
	size_t	width;
	char	*line;
	char	*to_free;

	i = -1;
	width = count_rows(map);
	while (map[++i])
	{
		if (ft_strlen(map[i]) != width)
		{
			line = ft_calloc(sizeof(char), (width + 1));
			ft_memset(line, ' ', width);
			j = 0;
			while (map[i][j])
			{
				line[j] = map[i][j];
				j++;
			}
			to_free = map[i];
			map[i] = line;
			free(to_free);
		}
	}
}

static int	check_walls(char **map)
{
	int	x;
	int	y;
	int	ln;
	int	col;

	y = -1;
	col = count_rows(map);
	ln = 0;
	while (map[ln])
		ln++;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("NESW0", map[y][x]))
			{
				if ((x == 0 || y == 0 || x == col - 1 || y == ln - 1) || \
					(map[y + 1][x] == ' ' || map[y - 1][x] == ' ' ||
					map[y][x + 1] == ' ' || map[y][x - 1] == ' '))
					return (1);
			}
		}
	}
	return (0);
}

char	**get_map(char **map, int lines)
{
	int	chars;

	while (*map && (**map != ' ' && **map != '1' && **map != '0'))
	{
		map++;
		lines--;
	}
	if (!map || !*map)
		return ((void) printf("Error\nMap is empty.\n"), NULL);
	if (is_separated(map, lines))
		return ((void) printf("Error\nMap is separated.\n"), NULL);
	chars = forbidden_char(map);
	if (chars == -1)
		return ((void) printf("Error\nMap contains forbidden char.\n"), NULL);
	if (chars != 1)
		return ((void) printf("Error\nOnly single-player.\n"), NULL);
	fill_spaces(map);
	if (check_walls(map))
		return ((void) printf("Error\nMap is not closed.\n"), NULL);
	return (map);
}

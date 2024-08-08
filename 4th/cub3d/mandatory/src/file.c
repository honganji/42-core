/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:27:27 by mkijewsk          #+#    #+#             */
/*   Updated: 2024/07/24 19:25:09 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	file_lines(char *filename)
{
	char	*line;
	int		count;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

char	**file_to_arr(char *filename, int lines)
{
	char	**arr;
	char	*line;
	int		fd;
	int		i;

	if (!lines)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	arr = malloc(sizeof(char *) * (lines + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		line = get_next_line(fd);
		arr[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	arr[i] = NULL;
	close(fd);
	return (arr);
}

int	count_rows(char **map)
{
	size_t	width;
	int		i;

	i = 0;
	width = 0;
	while (map[i])
	{
		if (width < ft_strlen(map[i]))
			width = ft_strlen(map[i]);
		i++;
	}
	return (width);
}

t_scene	*parse_scene(char *filename)
{
	t_scene	*desc;
	char	**arr;
	char	**map;
	int		lines;

	lines = file_lines(filename);
	arr = file_to_arr(filename, lines);
	if (!arr)
		return ((void) printf("Error\nFailed to open the file.\n"), NULL);
	if (!*arr)
		return (free_arr(arr), NULL);
	desc = ft_calloc(sizeof(t_scene), 1);
	if (!desc)
		return (NULL);
	if (assing_identifires(arr, desc))
		return ((void) printf("Error\nIncorrect identifier(s).\n"), \
		free_arr(arr), free_scene(desc), NULL);
	map = get_map(arr, lines);
	if (!map)
		return (free_arr(arr), free_scene(desc), NULL);
	desc->map = ft_arrdup(map);
	if (!desc->map)
		return (free(desc), NULL);
	free_arr(arr);
	return (desc);
}

int	skip_spaces(char *line)
{
	char	*res;

	res = line;
	while (line && *line == ' ')
		line++;
	if (*line == '2' || *line == '1' || *line == '0')
		return (1);
	while (line && *line)
		*res++ = *line++;
	*res = '\0';
	return (0);
}

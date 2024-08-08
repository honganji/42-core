/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:42:58 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/26 16:44:48 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static char	*skip_identifier(char *line)
{
	while (line && *line != ' ')
		line++;
	while (line && *line == ' ')
		line++;
	remove_spaces(line);
	return (line);
}

static int	check_rgb_format(char *line)
{
	int	i;
	int	count_comma;
	int	count_num;

	i = 0;
	count_comma = 0;
	count_num = 0;
	while (line && line[i])
	{
		if (ft_isdigit(line[i]))
			count_num++;
		else if (line[i] == ',')
		{
			if (count_num > 3 || count_num == 0)
				return (3);
			count_num = 0;
			count_comma++;
		}
		else
			return (2);
		i++;
	}
	if (count_comma != 2)
		return (4);
	return (0);
}

static long	assign_rgb(char *line)
{
	long	red;
	int		green;
	int		blue;

	line = skip_identifier(line);
	if (check_rgb_format(line))
		return (0);
	red = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	green = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	blue = ft_atoi(line);
	if (red < 0 || red > 255
		|| green < 0 || green > 255
		|| blue < 0 || blue > 255
		|| !*line)
		return (0);
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

int	assing_identifires(char **arr, t_scene *description)
{
	while (arr && *arr)
	{
		if (skip_spaces(*arr))
			break ;
		if (!description->no && !ft_strncmp(*arr, "NO ", 3))
			description->no = ft_strdup(skip_identifier(*arr++));
		else if (!description->ea && !ft_strncmp(*arr, "EA ", 3))
			description->ea = ft_strdup(skip_identifier(*arr++));
		else if (!description->so && !ft_strncmp(*arr, "SO ", 3))
			description->so = ft_strdup(skip_identifier(*arr++));
		else if (!description->we && !ft_strncmp(*arr, "WE ", 3))
			description->we = ft_strdup(skip_identifier(*arr++));
		else if (!description->f && !ft_strncmp(*arr, "F ", 2))
			description->f = assign_rgb(*arr++);
		else if (!description->c && !ft_strncmp(*arr, "C ", 2))
			description->c = assign_rgb(*arr++);
		else if (!**arr)
			arr++;
		else
			return (1);
	}
	if (!description->no || !description->ea || !description->so \
		|| !description->we || !description->f || !description->c)
		return (1);
	return (0);
}

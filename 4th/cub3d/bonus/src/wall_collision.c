/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:00:35 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/29 16:38:34 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static int	get_x(t_data *data, int step, double diff, char sign)
{
	if (sign == '+')
		return (floor((float)(data->x + step * cos(data->angle + diff)
				+ data->side * 0.2) / data->side));
	else
		return (floor((float)(data->x + step * cos(data->angle + diff)
				- data->side * 0.2) / data->side));
}

static int	get_y(t_data *data, int step, double diff, char sign)
{
	if (sign == '+')
		return (floor((float)(data->y + step * sin(data->angle + diff)
				+ data->side * 0.2) / data->side));
	else
		return (floor((float)(data->y + step * sin(data->angle + diff)
				- data->side * 0.2) / data->side));
}

static bool	check_char(char c, t_data *data, int step, double diff)
{
	int	x;
	int	y;

	x = floor((float)(data->x + step * cos(data->angle + diff)) / data->side);
	y = floor((float)(data->y + step * sin(data->angle + diff)) / data->side);
	if (data->scene->map[get_y(data, step, diff, '+')][x] == c
		|| data->scene->map[get_y(data, step, diff, '-')][x] == c
		|| data->scene->map[y][get_x(data, step, diff, '+')] == c
		|| data->scene->map[y][get_x(data, step, diff, '-')] == c
		|| data->scene->map[get_y(data, step, diff, '-')]
		[get_x(data, step, diff, '-')] == c
		|| data->scene->map[get_y(data, step, diff, '+')]
		[get_x(data, step, diff, '+')] == c
		|| data->scene->map[get_y(data, step, diff, '+')]
		[get_x(data, step, diff, '-')] == c
		|| data->scene->map[get_y(data, step, diff, '-')]
		[get_x(data, step, diff, '+')] == c)
		return (false);
	else
		return (true);
}

bool	check_wall(t_data *data, int step, double diff)
{
	if (!check_char('1', data, step, diff)
		|| !check_char('D', data, step, diff))
		return (false);
	return (true);
}

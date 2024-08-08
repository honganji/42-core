/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:53:33 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/16 14:19:06 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_wall_and_col(t_data *data, int diff_x, int diff_y)
{
	if (data->map[data->position.y + diff_y][data->position.x + diff_x] == 'C')
		data->count++;
	if (data->position.y + diff_y < 0 || data->position.x + diff_x < 0)
		return (1);
	if (data->map[data->position.y + diff_y][data->position.x + diff_x] == '1')
		return (1);
	return (0);
}

static void	move_helper(t_data *data, int diff_x, int diff_y)
{
	int	new_x;
	int	new_y;

	new_x = data->position.x + diff_x;
	new_y = data->position.y + diff_y;
	if (data->map[data->position.y][data->position.x] == 'E')
	{
		update_image(data, '0', data->position.x, data->position.y);
		update_image(data, 'E', data->position.x, data->position.y);
		update_image(data, 'P', new_x, new_y);
	}
	else
	{
		update_image(data, '0', data->position.x, data->position.y);
		if (data->map[new_y][new_x] == 'E')
		{
			update_image(data, 'P', new_x, new_y);
			data->map[new_y][new_x] = 'E';
		}
		else
			update_image(data, 'P', new_x, new_y);
	}
}

void	move(t_data *data, int diff_x, int diff_y)
{
	if (!check_wall_and_col(data, diff_x, diff_y))
	{
		move_helper(data, diff_x, diff_y);
		data->position.x += diff_x;
		data->position.y += diff_y;
		data->move_count++;
		ft_printf("move count: %d\n", data->move_count);
	}
}

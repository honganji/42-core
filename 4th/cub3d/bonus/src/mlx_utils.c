/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:07:03 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/24 19:34:41 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

float	initial_direction(char d)
{
	const float	point = 0.01;

	if (d == 'E')
		return (point);
	else if (d == 'S')
		return (M_PI / 2 + point);
	else if (d == 'W')
		return (M_PI + point);
	else
		return (M_PI * 3 / 2 + point);
}

int	reverse_bits(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0x000000FF) << 24;
	b |= (c & 0x0000FF00) << 8;
	b |= (c & 0x00FF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (fill_color(b));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:07:03 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/26 16:40:20 by ytoshihi         ###   ########.fr       */
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
	if (d == 'E')
		return (0);
	else if (d == 'S')
		return (M_PI / 2);
	else if (d == 'W')
		return (M_PI);
	else
		return (M_PI * 3 / 2);
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

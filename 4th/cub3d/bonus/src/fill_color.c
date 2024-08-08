/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:29:39 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/26 16:25:15 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	fill_color(int color)
{
	uint8_t	alpha;

	alpha = color & 0xFF;
	if (alpha < 0xF0)
		return (0xa0a0a0FF);
	return (color);
}

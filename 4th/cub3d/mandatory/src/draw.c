/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:10:15 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/07 21:34:00 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	draw_sq(void *img, int side)
{
	int	x;
	int	y;

	y = 0;
	while (y < side)
	{
		x = 0;
		while (x < side)
		{
			mlx_put_pixel(img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_circle(void *img, int diameter, int color)
{
	int	x;
	int	y;
	int	radius;

	radius = diameter / 2;
	y = -radius;
	while (y < radius)
	{
		x = -radius;
		while (x < radius)
		{
			if (x * x + y * y < (radius) * (radius))
				mlx_put_pixel(img, x + radius, y + radius, color);
			x++;
		}
		y++;
	}
}

void	draw_background(void *img, int floor, int ceil)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				mlx_put_pixel(img, x, y, floor);
			else
				mlx_put_pixel(img, x, y, ceil);
			x++;
		}
		y++;
	}
}

void	draw_ray(void *img, int border, int angle)
{
	int	x;
	int	y;

	y = 0;
	while (y < border)
	{
		x = 0;
		while (x < border)
		{
			if (x * cos(angle) + y * sin(angle) == 0)
				mlx_put_pixel(img, x, y, 0xFF00FFFF);
			x++;
		}
		y++;
	}
}

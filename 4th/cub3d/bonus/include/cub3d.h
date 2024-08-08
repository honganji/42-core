/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:46:45 by mkijewsk          #+#    #+#             */
/*   Updated: 2024/07/27 17:53:25 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libraries/42-c-library/library.h"
# include <stdbool.h>
# include "parsing.h"
# include "utils.h"
# include <MLX42/MLX42.h>
# include <math.h>
# include <limits.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define IMG_NORTH "imgs/wall1.png"
# define IMG_EAST "imgs/wall1.png"
# define IMG_SOUTH "imgs/wall1.png"
# define IMG_WEST "imgs/wall1.png"
# define IMG_DOOR "imgs/door.png"
# define IMG_NUM 10
# define MAP_SIZE 200
# define MAP_OFFSET 10
# define IMG_SPRITE "imgs/sprite"

typedef struct s_scene
{
	char	**map;
	char	*no;
	char	*ea;
	char	*so;
	char	*we;
	int		f;
	int		c;
}	t_scene;

typedef struct s_data
{
	void			*mlx;
	int				side;
	t_scene			*scene;
	float			x;
	float			y;
	float			angle;
	double			plane_x;
	double			plane_y;
	int				box_x;
	int				box_y;
	int				ln;
	int				col;
	mlx_image_t		*map;
	mlx_image_t		*frame;
	mlx_image_t		*background;
	mlx_image_t		*circle;
	mlx_image_t		*direction;
	mlx_image_t		*ray;
	mlx_texture_t	*textures[IMG_NUM];
	uint32_t		*pixel_array[IMG_NUM];
	int				sprite_len;
	bool			is_sprite;
	int				sprite_width;
	int				sprite_init_pos;	
	int				max_height;
	int				last_sprite_width;
	int				sprite_index;
	int				sprite_count;
	int				old_box_x;
	int				old_box_y;
	double			old_xdelta;
	int				old_ydelta;
	int				cooldown;
}	t_data;

#endif

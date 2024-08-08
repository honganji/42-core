/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:25:10 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/19 16:01:40 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define IMG_BG "./images/tatami.png"
# define IMG_WALL "./images/stone.png"
# define IMG_COLLECTIBLE "./images/protain_powder.png"
# define IMG_EXIT "./images/castle.png"
# define IMG_PLAYER "./images/oliver.png"
# define IMG_GOAL_MES "./images/goal.png"
# define IMG_PIXEL 100
# define IMG_NUM 6

# include "../libs/42-c-library/library.h"
# include <MLX42/MLX42.h>
# include <memory.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_coord
{
	int	x;
	int	y;
}t_coord;

typedef struct s_data
{
	void			*mlx;
	mlx_texture_t	*textures[IMG_NUM];
	mlx_image_t		*images[IMG_NUM];
	char			**map;
	t_coord			size;
	t_coord			position;
	int				count;
	int				col_sum;
	int				move_count;
}t_data;

typedef struct s_count
{
	int	p;
	int	c;
	int	e;
	int	x;
	int	y;
}t_count;

void	create_map(t_data *data, char *map_path);
void	error(char *err_meg);
void	key_hook(mlx_key_data_t keydata, void *param);
void	move(t_data *data, int diff_x, int diff_y);
void	update_image(t_data *data, char prop, int x, int y);
void	register_images(t_data *data);
void	loop_func(void *param);
int		check_walls(t_data *data);
void	check_line_num(char *map_path);
int		check_path(t_data *data);
char	**copy_map(t_data *data);
int		check_objects(t_data *data);

#endif
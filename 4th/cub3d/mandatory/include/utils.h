/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:52:17 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/27 16:01:43 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

typedef struct s_data	t_data;
typedef struct s_scene	t_scene;

typedef struct s_param_vl
{
	int		x;
	int		length;
	t_data	*data;
	int		side;
	double	wall_pos;
}	t_param_vl;

typedef struct s_param_ray
{
	int		x;
	double	screen;
	double	pos_x;
	double	pos_y;
	double	ray_x;
	double	ray_y;
	int		step_x;
	int		step_y;
	double	box_dist_x;
	double	box_dist_y;
	double	delta_x;
	double	delta_y;
	double	wall_pos;
	int		side;
	double	wall_dist;
	char	**map;
}	t_param_ray;

typedef struct s_param_img
{
	int		index;
	char	*path;
	char	*images[4];
}	t_param_img;

void	ft_init_mlx(t_data *data);
void	clean_data(t_data *data);
void	clean(t_data *data);
void	ray(void *value);
void	draw_map(void *param);
void	free_scene(t_scene *scene);
void	key_hook(void *param);
int		map_height(char **map);
float	initial_direction(char d);
int		reverse_bits(int c);
void	draw_sq(void *img, int side);
void	draw_circle(void *img, int diameter, int color);
void	draw_background(void *img, int floor, int ceil);
void	draw_map(void *param);
void	draw_vertical_line(t_param_vl *param);
void	initialize_ray(t_param_ray *param, t_data *data);
void	initialize_step(t_param_ray *param, t_data *data);
void	get_box_size(t_param_ray *param, t_data *data);
void	render(t_param_ray *param, t_data *data);
void	store_nesw_path(t_data *data);
void	clean_textures(t_data *data, int index);
int		skip_spaces(char *line);
int		fill_color(int color);
void	remove_spaces(char *s);
bool	check_wall(t_data *data, int step, double diff);

#endif

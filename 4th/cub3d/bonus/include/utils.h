/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:52:17 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/27 17:52:55 by ytoshihi         ###   ########.fr       */
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
	int		door_hit;
	char	**map;
	char	c;
}	t_param_ray;

typedef struct s_param_img
{
	int		index;
	char	*path;
	char	*images[5];
	int		fd;
}	t_param_img;

typedef struct s_param_sq
{
	int			x;
	int			y;
	int			color;
}	t_param_sq;

void			ft_init_mlx(t_data *data);
void			initial_position(void *param);
void			clean_data(t_data *data);
void			free_scene(t_scene *scene);
void			clean(t_data *data);
void			key_hook(void *param);
int				map_height(char **map);
float			initial_direction(char d);
int				reverse_bits(int c);
void			move(void *param);
void			draw_sq(t_data *data, t_param_sq param);
void			draw_circle(void *img, int diameter, int color);
void			draw_background(void *img, int floor, int ceil);
void			draw_map(t_data *data);
void			draw_vertical_line(t_param_vl *param);
void			initialize_ray(t_param_ray *param, t_data *data);
void			initialize_step(t_param_ray *param, t_data *data);
void			get_box_size(t_param_ray *param, t_data *data);
void			render(t_param_ray *param, t_data *data);
void			initialize_ray_sprite(t_param_ray *param, t_data *data);
void			initialize_step_sprite(t_param_ray *param, t_data *data);
void			get_box_size_sprite(t_param_ray *param, t_data *data);
void			render_sprite(t_param_ray *param, t_data *data);
void			store_textures(t_data *data);
void			draw_contour(t_data *data);
void			draw_player(t_data *data);
void			set_cursor(double ydelta, double x_delta, void *param);
void			count_width(t_param_ray *param, t_data *data);
void			get_sprite_width(t_data *data, t_param_ray *param);
void			store_max_height(t_param_ray *param, t_data *data);
void			draw_sprite(t_param_ray *param, t_data *data);
void			initialize_x(t_param_ray *param, t_data *data);
void			get_sprite_size(t_param_ray *param, t_data *data, int *tmp_x);
void			manage_sprites(t_data *data);
void			cal_box(t_param_ray *param, t_data *data);
unsigned int	get_texture_color(t_param_ray *param, t_data *data, int y_r);
void			cal_width(t_param_ray *param, t_data *data, int old_box_x,
					int old_box_y);
void			render_sp_line(t_param_ray *param, t_data *data, int tmp_box_x,
					int tmp_box_y);
int				fill_color(int color);
void			check_door(t_param_ray *param, t_data *data);
void			clean(t_data *data);
void			clean_textures(t_data *data, int index);
int				skip_spaces(char *line);
void			remove_spaces(char *s);
bool			check_wall(t_data *data, int step, double diff);

#endif

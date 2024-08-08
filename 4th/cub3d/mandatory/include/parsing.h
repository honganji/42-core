/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:29:54 by mkijewsk          #+#    #+#             */
/*   Updated: 2024/07/07 20:50:02 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef struct s_scene	t_scene;

char	**get_map(char **map, int lines);
int		count_rows(char **map);
void	free_arr(char **arr);
char	**ft_arrdup(char **arr);
int		assing_identifires(char **arr, t_scene *description);
int		count_rows(char **map);
char	**file_to_arr(char *filename, int lines);
int		file_lines(char *filename);
t_scene	*parse_scene(char *filename);

#endif

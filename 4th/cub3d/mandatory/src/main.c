/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:04:42 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/07/26 16:09:46 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_data	*data;

	if (argc == 2)
	{
		if (!ft_strrchr(argv[1], '.'))
			return ((void) printf("Error\nWrong extension.\n"), 1);
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 4) != 0)
			return ((void) printf("Error\nWrong extension.\n"), 1);
		scene = parse_scene(argv[1]);
		if (!scene)
			return (1);
		data = (t_data *)ft_calloc(1, sizeof(t_data));
		data->scene = scene;
		ft_init_mlx(data);
		mlx_loop(data->mlx);
		clean_data(data);
		free_scene(scene);
		return (0);
	}
	printf("Error\nCorrect prompt: ./cub3d 'file.cub'\n");
	return (1);
}

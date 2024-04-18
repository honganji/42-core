/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:30:47 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/18 14:39:00 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_data	*data;
	char	*map_path;

	if (argc != 2)
		error("The number of arguments is not right...");
	map_path = argv[1];
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		error("Fail to allocate memory to data...");
	data->count = 0;
	data->move_count = 0;
	data->mlx = mlx_init(WIDTH, HEIGHT, "Muscle Game", true);
	register_images(data);
	create_map(data, map_path);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_close_hook(data->mlx, close_func, data);
	mlx_loop_hook(data->mlx, loop_func, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}

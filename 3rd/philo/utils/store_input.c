/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:19:48 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/06 15:34:24 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief Get the length of an array
 * 
 * @param arr array of strings
 * 
 * @return int
*/
static int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/**
 * @brief Store a string as int type
 * 
 * @param argc the number of argument
 * @param argv the array of arguments
 * @param args the array of numbers
 * @param i index of a number
 * 
 * @return void
*/
static int	store_int(int *argc, char **arr, int *args, int i)
{
	if (*argc && ft_atoi(arr[i]) != (int)ft_atoi(arr[i]))
	{
		error();
		return (0);
	}
	if (*argc && arr[i])
		args[i] = (int)ft_atoi(arr[i]);
	else
		args[i] = -1;
	(*argc)--;
	return (1);
}

/**
 * @brief Check if the input is only one.
 * If so, using ft_split function and check if all the string is number
 * Then store into args valuable
 * 
 * @param argc the number of arguments
 * @param argv array of arguments
 * @param args array of int
 * 
 * @return int
*/
static int	check_if_one(int argc, char **argv, int args[5])
{
	char	**arr;
	int		i;

	i = -1;
	if (argc != 2)
		return (0);
	arr = ft_split(argv[1], ' ');
	if (arr_len(arr) < 4)
	{
		error();
		return (free_str_arr(arr), 0);
	}
	argc = arr_len(arr);
	while (++i < 5)
	{
		if (arr[i] && !ft_isnum(arr[i]))
		{
			error();
			return (free_str_arr(arr), 0);
		}
		if (!store_int(&argc, arr, args, i))
			return (free_str_arr(arr), 0);
	}
	return (free_str_arr(arr), 1);
}

/**
 * @brief Check if the arguments has 4 or 5 input and if all of them are num
 * 
 * @param argc number of arguments
 * @param argv array of inputs
 * @param args array of nums that holds 5 input parameters
 * 
 * @return void
*/
static int	check_num_args(int argc, char **argv, int args[5])
{
	int	i;

	i = 0;
	if (argc == 2)
		return (0);
	if (!(argc == 5 || argc == 6))
	{
		error();
		return (0);
	}
	while (++i < argc)
	{
		if (!ft_isnum(argv[i]))
		{
			error();
			return (0);
		}
	}
	i = -1;
	modify_argv(argc, &argv);
	argc--;
	while (++i < 5)
		if (!store_int(&argc, argv, args, i))
			return (0);
	return (1);
}

/**
 * @brief Store input parameters as int array
 * 
 * @param argc number of arguments
 * @param argv array of inputs
 * @param args array of nums that holds 5 input parameters
 * 
 * @return void
*/
int	store_input(int argc, char **argv, int args[5])
{
	if (check_if_one(argc, argv, args))
		return (1);
	if (!check_num_args(argc, argv, args))
		return (0);
	return (1);
}

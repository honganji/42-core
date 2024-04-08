/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:35:08 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/08 18:51:02 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

int	check_unique(int argc, long *array)
{
	long	tmp;
	int		count_1;
	int		count_2;

	count_1 = 0;
	count_2 = 0;
	while (count_1 < argc - 1)
	{
		tmp = array[count_1];
		count_2 = count_1 + 1;
		while (count_2 < argc)
		{
			if (tmp == array[count_2++])
			{
				free(array);
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
		}
		count_1++;
	}
	return (1);
}

static int	check_type_int(int argc, char **argv, long *array)
{
	int		count;
	long	tmp;

	count = 0;
	while (count < argc)
	{
		tmp = ft_atoi(argv[count++]);
		if (tmp != (int)tmp)
		{
			free(array);
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
	}
	return (1);
}

int	check_num(int argc, char **argv, long *array)
{
	int	argv_count;
	int	str_count;

	argv_count = 0;
	str_count = 0;
	while (argv_count < argc)
	{
		if (argv[argv_count][str_count] == '-'
			|| argv[argv_count][str_count] == '+')
			str_count++;
		if (!argv[argv_count][str_count])
			return (0);
		while (argv[argv_count][str_count])
		{
			if (!ft_isdigit(argv[argv_count][str_count++]))
			{
				free(array);
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
		}
		str_count = 0;
		argv_count++;
	}
	return (1);
}

static int	split_args(int *argc, char *args, long **array)
{
	char	**str;
	int		count;

	str = ft_split(args, ' ');
	count = 0;
	while (str[count])
		count++;
	*argc = count;
	free(*array);
	*array = (long *)malloc(count * sizeof(long));
	count = 0;
	if (!check_num(*argc, str, *array) || !check_type_int(*argc, str, *array))
	{
		free_arr(str);
		return (0);
	}
	while (count < *argc)
	{
		(*array)[count] = ft_atoi(str[count]);
		count++;
	}
	free_arr(str);
	return (1);
}

int	store_arg(int *argc, char **argv, long **array)
{
	int	count;

	count = 0;
	if (*argc == 1)
	{
		if (!split_args(argc, argv[0], array))
			return (0);
	}
	else
	{
		if (!check_num(*argc, argv, *array) || !check_type_int(*argc, argv,
				*array))
			return (0);
		while (count < *argc)
		{
			(*array)[count] = ft_atoi(argv[count]);
			count++;
		}
	}
	if (!check_unique(*argc, *array) || !*(argv[0]))
		return (0);
	return (1);
}

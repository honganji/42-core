/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:35:08 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/03 11:55:30 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

int	check_unique(int argc, long *array)
{
	long	tmp;
	int		count_1;
	int		count_2;

	tmp = array[count_1++];
	count_1 = 0;
	count_2 = 0;
	while (count_1 < argc - 1)
	{
		tmp = array[count_1];
		count_2 = count_1 + 1;
		while (count_2 < argc - 1)
		{
			if (tmp == array[count_2++])
				return (0);
		}
		count_1++;
	}
	return (1);
}

static int	check_type_int(int argc, char **argv)
{
	int		count;
	long	tmp;

	count = 1;
	while (count < argc)
	{
		tmp = ft_atoi(argv[count++]);
		if (tmp != (int)tmp)
			return (0);
	}
	return (1);
}

int	check_num(int argc, char **argv)
{
	int	argv_count;
	int	str_count;

	argv_count = 1;
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
				return (0);
		}
		str_count = 0;
		argv_count++;
	}
	return (1);
}

int	store_arg(int argc, char **argv, long **array)
{
	int		count;
	long	tmp;

	count = 1;
	if (!check_num(argc, argv) || !check_type_int(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		free(*array);
		return (0);
	}
	count = 1;
	while (count < argc)
	{
		(*array)[count - 1] = ft_atoi(argv[argc - count]);
		count++;
	}
	if (!check_unique(argc, *array))
	{
		ft_putstr_fd("Error\n", 1);
		free(*array);
		return (0);
	}
	return (1);
}

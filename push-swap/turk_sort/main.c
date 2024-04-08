/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:05:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/08 18:43:18 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_argv(int *argc, char ***argv)
{
	int	i;

	i = 0;
	while (i < *argc - 1)
	{
		(*argv)[i] = (*argv)[i + 1];
		i++;
	}
	(*argc)--;
}

int	main(int argc, char **argv)
{
	long	*array;
	t_list	*a;
	t_list	*b;
	int		i;

	i = 0;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		shift_argv(&argc, &argv);
		array = (long *)malloc((argc) * sizeof(long));
		if (!store_arg(&argc, argv, &array))
			return (0);
		while (i < argc)
		{
			ft_lstadd_back(&a, ft_lstnew(&(array[i])));
			i++;
		}
		if (!check_lst(a))
			push_swap(&a, &b);
		free(array);
		clear_lst(&a);
	}
	return (0);
}

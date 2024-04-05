/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:05:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/05 20:17:17 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	long	*array;
	t_list	*a;
	t_list	*b;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		array = (long *)malloc((argc - 1) * sizeof(long));
		if (!store_arg(argc, argv, &array))
			return (0);
		while (i < argc)
		{
			ft_lstadd_front(&a, ft_lstnew(&(array[i - 1])));
			i++;
		}
		push_swap(&a, &b);
		free(array);
		clear_lst(&a);
	}
	else
		ft_putstr_fd("ERROR", 1);
	return (0);
}

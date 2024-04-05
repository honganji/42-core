/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:05:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/05 20:17:10 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(t_list **a, long *array)
{
	if (check_result(*a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(array);
	clear_lst(a);
}

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
		check(&a, array);
	}
	else
		ft_putstr_fd("ERROR", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:05:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/31 15:53:06 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	test(void *num)
// {
// 	printf("lst element: %d\n", *(int *)num);
// }

// int	main(void)
// {
// 	int		*array_a;
// 	t_list	*lst_a;
// 	t_list	*lst_b;
// 	int		i;
// 	int		size;

// 	// put values in list a and b
// 	size = 1000;
// 	i = size;
// 	array_a = ft_calloc(size, sizeof(int));
// 	lst_a = NULL;
// 	lst_b = NULL;
// 	while (i >= 0)
// 	{
// 		array_a[i] = i;
// 		i--;
// 	}
// 	i = size;
// 	while (i >= 0)
// 	{
// 		swap_in_array(array_a, rand() % size, rand() % size);
// 		i--;
// 	}
// 	while (++i < size)
// 	{
// 		ft_lstadd_front(&lst_a, ft_lstnew(&(array_a[i])));
// 	}

// 	// display list a and b
// 	printf("list_a: \n");
// 	ft_lstiter(lst_a, test);
// 	printf("\nlist_b: \n");
// 	ft_lstiter(lst_b, test);

// 	// execute push swap
// 	push_swap(&lst_a, &lst_b);

// 	// display list a and b
// 	printf("\nlist_a: \n");
// 	ft_lstiter(lst_a, test);
// 	printf("\nlist_b: \n");
// 	ft_lstiter(lst_b, test);
// 	return (0);
// }

// to deal with input parameter
int	main(int argc, char *argv[])
{
	int		array[argc];
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;
	int		num;

	// put values in list a and b
	num = 0;
	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	while (i < argc)
	{
		array[i - 1] = ft_atoi(argv[i]);
		ft_lstadd_front(&lst_a, ft_lstnew(&(array[i - 1])));
		i++;
	}
	// execute push swap
	push_swap(&lst_a, &lst_b);
	return (0);
}

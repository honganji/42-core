/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:05:38 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/02 19:02:46 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	long	*array;
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;

	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	array = (long *)malloc((argc - 1) * sizeof(long));
	if (!check_arg(argc, argv, &array))
		return (0);
	while (i < argc)
	{
		ft_lstadd_front(&lst_a, ft_lstnew(&(array[i - 1])));
		i++;
	}
	push_swap(&lst_a, &lst_b);
	if (check_result(lst_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(array);
	return (0);
}

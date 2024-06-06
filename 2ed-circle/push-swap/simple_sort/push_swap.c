/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:36:01 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/31 15:15:11 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	test(void *num)
// {
// 	printf("lst element: %d\n", *(int *)num);
// }

void	push_swap(t_list **a, t_list **b)
{
	if (!*a)
		return ;
	while (*a)
	{
		if (!(*b))
			pb(a, b);
		if (*(int *)((*b)->content) <= *(int *)((*a)->content))
			pb(a, b);
		else
		{
			pa(a, b);
			swap(a);
		}
	}
	while (*b)
		pa(a, b);
}

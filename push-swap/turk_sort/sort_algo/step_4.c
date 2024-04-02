/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:28:19 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/01 23:33:48 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"

int	get_last_element(t_list *a)
{
	while (a->next)
		a = a->next;
	return (*(int *)a->content);
}

void	push_all_from_b(t_list **a, t_list **b)
{
	int	count;

	count = 0;
	while (*b)
	{
		pa(a, b);
		while (get_last_element(*a) == *(int *)(*a)->content - 1 && count < 3)
		{
			rra(a);
			count++;
		}
	}
}

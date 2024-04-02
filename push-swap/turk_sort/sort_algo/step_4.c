/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:28:19 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/02 19:27:38 by ytoshihi         ###   ########.fr       */
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
	t_ab_op	ab_op;

	count = 0;
	while (*b)
	{
		while (get_last_element(*a) > *(int *)(*b)->content && count < 3)
		{
			rra(a);
			count++;
		}
		pa(a, b);
	}
	cal_op(*a, get_min_num(*a), &ab_op.a_op);
	ab_op.b_op.times = 0;
	sort_a_b(ab_op, a, b);
}

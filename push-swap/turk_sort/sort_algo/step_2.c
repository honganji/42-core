/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:40:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/02 17:11:27 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"

static void	cal_op(t_list *lst, long num, t_op *op)
{
	int	size;
	int	count;

	size = ft_lstsize(lst);
	count = 0;
	while (lst && *(long *)lst->content != num)
	{
		lst = lst->next;
		count++;
	}
	if (count > size - count)
	{
		op->times = size - count;
		op->is_r = 0;
	}
	else
	{
		op->times = count;
		op->is_r = 1;
	}
}

static void	sort_a_b(t_ab_op final_ab_op, t_list **a, t_list **b)
{
	while (final_ab_op.a_op.times && final_ab_op.b_op.times
		&& final_ab_op.a_op.is_r == final_ab_op.b_op.is_r)
	{
		if (final_ab_op.a_op.is_r)
			rr(a, b);
		else
			rrr(a, b);
		final_ab_op.a_op.times--;
		final_ab_op.b_op.times--;
	}
	while (final_ab_op.a_op.times--)
	{
		if (final_ab_op.a_op.is_r)
			ra(a);
		else
			rra(a);
	}
	while (final_ab_op.b_op.times--)
	{
		if (final_ab_op.b_op.is_r)
			rb(b);
		else
			rrb(b);
	}
}

static void	put_right_place(t_list **a, t_list **b)
{
	t_ab_op	tmp_ab_op;
	t_ab_op	final_ab_op;
	t_list	*tmp;
	int		num;

	tmp = *a;
	num = 0;
	final_ab_op.sum = -1;
	while (tmp)
	{
		cal_op(*a, *(int *)tmp->content, &tmp_ab_op.a_op);
		cal_op(*b, search_min_num(*b, *(long *)tmp->content), &tmp_ab_op.b_op);
		tmp_ab_op.sum = tmp_ab_op.a_op.times + tmp_ab_op.b_op.times;
		if (final_ab_op.sum == -1 || tmp_ab_op.sum < final_ab_op.sum)
			final_ab_op = tmp_ab_op;
		tmp = tmp->next;
		num++;
	}
	sort_a_b(final_ab_op, a, b);
	pb(a, b);
}

void	push_with_sort(t_list **a, t_list **b)
{
	int		size;
	t_ab_op	ab_op;

	size = ft_lstsize(*a);
	while (size-- > 3)
		put_right_place(a, b);
	cal_op(*b, search_min_num(*b, 2147483647), &ab_op.b_op);
	ab_op.a_op.times = 0;
	sort_a_b(ab_op, a, b);
}

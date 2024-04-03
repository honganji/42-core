/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_with_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:40:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/03 12:41:06 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"

void	cal_op(t_list *lst, long num, t_op *op)
{
	int	size_a;
	int	count;

	size_a = ft_lstsize(lst);
	count = 0;
	while (lst && *(long *)lst->content != num)
	{
		lst = lst->next;
		count++;
	}
	if (count > size_a - count)
	{
		op->times = size_a - count;
		op->is_r = 0;
	}
	else
	{
		op->times = count;
		op->is_r = 1;
	}
}

void	sort_a_b(t_ab_op final_op, t_list **a, t_list **b)
{
	while (final_op.a.times && final_op.b.times
		&& final_op.a.is_r == final_op.b.is_r)
	{
		if (final_op.a.is_r)
			rr(a, b);
		else
			rrr(a, b);
		final_op.a.times--;
		final_op.b.times--;
	}
	while (final_op.a.times--)
	{
		if (final_op.a.is_r)
			ra(a);
		else
			rra(a);
	}
	while (final_op.b.times--)
	{
		if (final_op.b.is_r)
			rb(b);
		else
			rrb(b);
	}
}

static void	put_right_place(t_list **a, t_list **b)
{
	t_ab_op	tmp_op;
	t_ab_op	final_op;
	t_list	*tmp_lst;
	int		num_a;

	tmp_lst = *a;
	num_a = 0;
	final_op.sum = -1;
	while (tmp_lst)
	{
		num_a = *(long *)tmp_lst->content;
		cal_op(*a, num_a, &tmp_op.a);
		cal_op(*b, search_next_num(*b, num_a), &tmp_op.b);
		tmp_op.sum = tmp_op.a.times + tmp_op.b.times;
		if (final_op.sum == -1 || tmp_op.sum < final_op.sum)
			final_op = tmp_op;
		tmp_lst = tmp_lst->next;
	}
	sort_a_b(final_op, a, b);
	pb(a, b);
}

void	final_sort(t_list **a, t_list **b)
{
	t_ab_op	final_op;

	cal_op(*b, get_max_num(*b), &final_op.b);
	final_op.a.times = 0;
	sort_a_b(final_op, a, b);
}

void	push_with_sort(t_list **a, t_list **b)
{
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	if (size_a <= 3)
	{
		if (size_b == 2
			&& *(int *)(*b)->content < *(int *)(*b)->next->content)
			sb(b);
		return ;
	}
	while (size_a-- > 3)
		put_right_place(a, b);
	final_sort(a, b);
}

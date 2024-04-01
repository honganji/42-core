/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:40:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/01 13:53:43 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"

static void	count_a_times(t_list *a, int num, t_operation *t_op)
{
	if (num > ft_lstsize(a) / 2 + 1)
	{
		t_op->a_times = ft_lstsize(a) - num;
		t_op->is_ra = 0;
	}
	else
	{
		t_op->a_times = num;
		t_op->is_ra = 1;
	}
}

static void	count_b_times(t_list *b, int num, t_operation *t_op)
{
	int	size;
	int	count;

	size = ft_lstsize(b);
	count = 0;
	while (*(int *)b->content != num)
	{
		b = b->next;
		count++;
	}
	if (count > size - count)
	{
		(*t_op).b_times = size - count;
		(*t_op).is_rb = 0;
	}
	else
	{
		(*t_op).b_times = count;
		(*t_op).is_rb = 1;
	}
}

static int	search_min_num(t_list *b, int num)
{
	int	min_diff;

	min_diff = INT_MAX;
	while (b)
	{
		if (*(int *)b->content - num < min_diff && *(int *)b->content - num > 0)
			min_diff = *(int *)b->content - num;
		b = b->next;
	}
	if (min_diff < 0)
		return (num);
	return (num + min_diff);
}

void	put_right_place(t_list **a, t_list **b)
{
	t_operation	t_op_tmp;
	t_operation	t_op_final;
	t_list		*tmp;
	int			num;
	int			min_total;

	tmp = *a;
	num = 0;
	t_op_final.a_times = -1;
	t_op_final.b_times = -1;
	min_total = -1;
	printf("first element in a: %d\n", *(int *)tmp->content);
	printf("a min times:%d, is_ra: %d\n", t_op_tmp.a_times, t_op_tmp.is_ra);
	printf("b min times:%d, is_rb: %d\n", t_op_tmp.b_times, t_op_tmp.is_rb);
	// printf("min & less than the num:%d\n", search_min_num(*b, *(int *)tmp->content));
	count_a_times(*a, 0, &t_op_tmp);
	// count_b_times(*a, 0, &t_op_tmp);
	count_b_times(*b, search_min_num(*b, *(int *)tmp->content), &t_op_tmp);
	while (tmp)
	{
		count_a_times(*a, num, &t_op_tmp);
		count_b_times(*b, search_min_num(*b, *(int *)tmp->content), &t_op_tmp);
		if (t_op_final.a_times == -1 || t_op_final.a_times + t_op_final.b_times > t_op_tmp.a_times + t_op_tmp.b_times)
			t_op_final = t_op_tmp;
		tmp = tmp->next;
		num++;
	}
	printf("a min times:%d, is_ra: %d\n", t_op_final.a_times, t_op_final.is_ra);
	printf("b min times:%d, is_rb: %d\n", t_op_final.b_times, t_op_final.is_rb);
	// printf("a min:%d, b_times: %d\n", t_op_final.a_times, t_op_final.b_times);
}

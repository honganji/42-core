/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:07:37 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/03 15:00:01 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"

int	get_max_num(t_list *b)
{
	int		max_num;

	max_num = *(int *)b->content;
	while (b)
	{
		if (*(int *)b->content > max_num)
			max_num = *(int *)b->content;
		b = b->next;
	}
	return (max_num);
}

int	get_min_num(t_list *b)
{
	int		min_num;

	min_num = *(int *)b->content;
	while (b)
	{
		if (*(int *)b->content < min_num)
			min_num = *(int *)b->content;
		b = b->next;
	}
	return (min_num);
}

long	search_next_num(t_list *b, long num)
{
	long		min_diff;

	min_diff = 2147483647;
	if (num < get_min_num(b) || num >= get_max_num(b))
		return (get_max_num(b));
	while (b)
	{
		if ((num - *(int *)b->content) < min_diff && num
			- *(int *)b->content > 0)
			min_diff = num - *(int *)b->content;
		b = b->next;
	}
	return (num - min_diff);
}

int	calculate_sum(t_ab_op op)
{
	int	sum;

	sum = 0;
	while (op.a.times && op.b.times && (op.a.is_r == op.b.is_r))
	{
		sum++;
		op.a.times--;
		op.b.times--;
	}
	while (op.a.times--)
		sum++;
	while (op.b.times--)
		sum++;
	return (sum);
}

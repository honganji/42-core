/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_2_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:07:37 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/02 19:17:23 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"

static int	get_max_num(t_list *b)
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

long	search_min_num(t_list *b, long num)
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

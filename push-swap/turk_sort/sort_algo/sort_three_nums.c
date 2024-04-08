/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:43:46 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/08 18:02:46 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"

static int	check_if_sorted(t_list *a)
{
	while (a->next)
	{
		if (*(int *)a->content > *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	sort_one_op(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*a)->content;
	second = *(int *)(*a)->next->content;
	third = *(int *)(*a)->next->next->content;
	if (first > second)
	{
		if (first > third)
			ra(a);
		else
			sa(a);
	}
	else if (second > third)
		rra(a);
}

static void	sort_two_op(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*a)->content;
	second = *(int *)(*a)->next->content;
	third = *(int *)(*a)->next->next->content;
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (third > first && second > third)
	{
		sa(a);
		ra(a);
	}
}

void	sort_three_nums(t_list **a)
{
	if (check_if_sorted(*a))
		return ;
	sort_two_op(a);
	if (check_if_sorted(*a))
		return ;
	sort_one_op(a);
}

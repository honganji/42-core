/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:08:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/31 18:25:03 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"

int	push_two_num(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 3)
		return (0);
	pb(a, b);
	pb(a, b);
	return (1);
}

// int	cal_pa_count(t_list *a)
// {
// 	int	count;
// 	int	min;

// 	count = 0;
// 	min = 1;
// 	while (a->content)
// 	{
// 		while (/* condition */)
// 		{
// 			/* code */
// 		}
// 		a = a->next;
// 	}
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_two_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:08:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/03 12:38:08 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"

int	push_two_num(t_list **a, t_list **b)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	if (size_a <= 1)
		return (0);
	else if (size_a == 2)
	{
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			sa(a);
		return (0);
	}
	else if (size_a >= 4)
	{
		pb(a, b);
		if (size_a >= 5)
			pb(a, b);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:08:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/02 18:44:57 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"

int	push_two_num(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 2)
		return (0);
	else if (ft_lstsize(*a) == 2)
	{
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			sa(a);
		return (0);
	}
	else if (ft_lstsize(*a) == 3)
		return (1);
	else if (ft_lstsize(*a) == 4)
	{
		pb(a, b);
		return (1);
	}
	pb(a, b);
	pb(a, b);
	return (1);
}

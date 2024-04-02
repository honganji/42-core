/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:08:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/02 14:00:29 by ytoshihi         ###   ########.fr       */
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

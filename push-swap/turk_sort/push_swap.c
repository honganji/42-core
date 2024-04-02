/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:36:01 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/02 19:34:00 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	if (!push_two_num(a, b))
		return ;
	push_with_sort(a, b);
	// sort_three_nums(a);
	push_all_from_b(a, b);
}

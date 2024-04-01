/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:36:01 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/01 13:53:57 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	test(void *num)
// {
// 	printf("lst element: %d\n", *(int *)num);
// }

void	push_swap(t_list **a, t_list **b)
{
	push_two_num(a, b);
	put_right_place(a, b);
}

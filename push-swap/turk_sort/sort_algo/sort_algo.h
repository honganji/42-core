/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:13:12 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/02 14:13:40 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGO_H
# define SORT_ALGO_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../utils/utils.h"

typedef struct op
{
	int	is_r;
	int	times;
}	t_op;

typedef struct ab_op
{
	t_op	a_op;
	t_op	b_op;
	int		sum;
}	t_ab_op;

int		push_two_num(t_list **a, t_list **b);
void	push_with_sort(t_list **a, t_list **b);
void	sort_three_nums(t_list **a);
void	push_all_from_b(t_list **a, t_list **b);
int		search_min_num(t_list *b, int num);

#endif

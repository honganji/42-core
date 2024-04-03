/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:13:12 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/03 12:51:32 by ytoshihi         ###   ########.fr       */
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
	t_op	a;
	t_op	b;
	int		sum;
}	t_ab_op;

int		push_two_num(t_list **a, t_list **b);
void	push_with_sort(t_list **a, t_list **b);
void	sort_three_nums(t_list **a);
void	push_all_to_a(t_list **a, t_list **b);
long	search_next_num(t_list *b, long num);
void	sort_a_b(t_ab_op final_ab_op, t_list **a, t_list **b);
void	cal_op(t_list *lst, long num, t_op *op);
int		get_min_num(t_list *b);
int		get_max_num(t_list *b);
int		calculate_sum(t_ab_op op);

#endif

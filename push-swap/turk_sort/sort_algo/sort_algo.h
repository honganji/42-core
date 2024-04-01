/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:13:12 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/01 13:52:41 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGO_H
# define SORT_ALGO_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../utils/utils.h"
#include <limits.h>

typedef struct operation
{
	int	is_ra;
	int	a_times;
	int	is_rb;
	int	b_times;
}	t_operation;

int		push_two_num(t_list **a, t_list **b);
void	put_right_place(t_list **a, t_list **b);

#endif

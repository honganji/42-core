/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:13:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/29 21:33:49 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./utils/utils.h"
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	push_swap(t_list **a, t_list **b);
int		check_if_unique(int num, int *array, int size);
void	swap_in_array(int *array, int i, int j);

#endif
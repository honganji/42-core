/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:13:29 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/06 17:47:08 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./utils/utils.h"
# include "./sort_algo/sort_algo.h"
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	push_swap(t_list **a, t_list **b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:15:50 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/30 14:29:29 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sa(t_list **lst_a)
{
	swap(lst_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **lst_b)
{
	swap(lst_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	ft_putstr_fd("ss\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:18:56 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/31 15:14:17 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	pa(t_list **lst_a, t_list **lst_b)
{
	push(lst_a, lst_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	push(lst_b, lst_a);
	ft_putstr_fd("pb\n", 1);
}

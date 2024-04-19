/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:32:28 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/30 14:34:05 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rra(t_list **lst_a)
{
	reverse_rotate(lst_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **lst_b)
{
	reverse_rotate(lst_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	ft_putstr_fd("rrr\n", 1);
}

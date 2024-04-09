/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:18:21 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/30 14:31:23 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ra(t_list **lst_a)
{
	rotate(lst_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **lst_b)
{
	rotate(lst_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
	ft_putstr_fd("rr\n", 1);
}

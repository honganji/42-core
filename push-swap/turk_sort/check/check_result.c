/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:27:39 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/04/02 18:33:59 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"

int	check_result(t_list *a)
{
	while (a->next)
	{
		if (*(int *)a->content > *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

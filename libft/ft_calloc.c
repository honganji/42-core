/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:23:15 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/10 20:20:37 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;
	int		tmp;

	tmp = num * size;
	if (num && size && (tmp / size != num))
		return (NULL);
	p = malloc(tmp);
	if (!p)
		return (NULL);
	ft_bzero(p, tmp);
	return (p);
}

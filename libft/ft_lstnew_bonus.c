/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:28:35 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/12 18:40:28 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_data;

	new_data = (t_list *)malloc(sizeof(t_list));
	if (!new_data)
		return (NULL);
	new_data->content = content;
	new_data->next = NULL;
	return (new_data);
}

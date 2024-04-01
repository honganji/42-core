/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:31:44 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/30 14:35:42 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	swap(t_list **lst)
{
	void	*tmp;

	if (!((*lst)->next))
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
}

void	rotate(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!((*lst)->next))
		return ;
	ft_lstadd_back(lst, ft_lstnew((*lst)->content));
	*lst = (*lst)->next;
	free(tmp);
}

void	reverse_rotate(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!((*lst)->next->next))
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(lst, ft_lstnew(tmp->next->content));
	free(tmp->next);
	tmp->next = NULL;
}

void	push(t_list **lst_dst, t_list **lst_src)
{
	t_list	*tmp;

	tmp = *lst_src;
	ft_lstadd_front(lst_dst, ft_lstnew((*lst_src)->content));
	*lst_src = (*lst_src)->next; 
	free(tmp);
}

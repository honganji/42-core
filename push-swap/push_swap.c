/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:36:01 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/03/29 15:45:01 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	test(void *num)
{
	printf("lst element: %d\n", *(int *)num);
}

// static void	swap(t_list *lst)
// {
// 	void	*tmp;

// 	if (!(lst->next))
// 		return ;
// 	tmp = lst->content;
// 	lst->content = lst->next->content;
// 	lst->next->content = tmp;
// }

// static void	rotate(t_list **lst)
// {
// 	t_list	*tmp;

// 	tmp = *lst;
// 	if (!((*lst)->next))
// 		return ;
// 	ft_lstadd_back(lst, ft_lstnew((*lst)->content));
// 	*lst = (*lst)->next;
// 	free(tmp);
// }

// static void	reverse_rotate(t_list **lst)
// {
// 	t_list	*tmp;

// 	tmp = *lst;
// 	if (!((*lst)->next->next))
// 		return ;
// 	while (tmp->next->next)
// 		tmp = tmp->next;
// 	ft_lstadd_front(lst, ft_lstnew(tmp->next->content));
// 	free(tmp->next);
// 	tmp->next = NULL;
// }

// static void	push(t_list **lst_dst, t_list **lst_src)
// {
// 	t_list	*tmp;

// 	tmp = *lst_src;
// 	ft_lstadd_front(lst_dst, ft_lstnew((*lst_src)->content));
// 	*lst_src = (*lst_src)->next; 
// 	free(tmp);
// }

int	main(void)
{
	int		*array_a;
	int		*array_b;
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;

	i = 10;
	array_a = (int *)malloc(i * sizeof(int));
	array_b = (int *)malloc(i * sizeof(int));
	lst_a = NULL;
	lst_b = NULL;
	while (--i >= 0)
	{
		array_a[i] = i;
		array_b[i] = i;
	}
	while (++i < 10)
	{
		ft_lstadd_front(&lst_a, ft_lstnew(&(array_a[i])));
		ft_lstadd_front(&lst_b, ft_lstnew(&(array_b[i])));
	}
	// swap(lst);
	// rotate(&lst);
	reverse_rotate(&lst_a);
	push(&lst_a, &lst_b);
	printf("list_a: \n");
	ft_lstiter(lst_a, test);
	printf("\n");
	printf("list_b: \n");
	ft_lstiter(lst_b, test);
	printf("\n");
	return (0);
}

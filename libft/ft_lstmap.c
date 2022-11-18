/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:38:53 by lcadinot          #+#    #+#             */
/*   Updated: 2022/11/16 12:57:31 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear(t_list *new_lst, t_list *elem, void (*del)(void *))
{
	ft_lstclear(&new_lst, del);
	ft_lstclear(&elem, del);
	free(new_lst);
	free(elem);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;

	if (!lst)
		return (0);
	elem = ft_lstnew(f(lst->content));
	new_lst = elem;
	if (!elem)
	{
		ft_clear(new_lst, elem, del);
		return (0);
	}
	lst = lst->next;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_clear(new_lst, elem, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}

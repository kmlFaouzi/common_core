/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:27:03 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/07 14:33:07 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nw_list;
	t_list	*new_elem;

	nw_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&nw_list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&nw_list, new_elem);
	}
	return (nw_list);
}

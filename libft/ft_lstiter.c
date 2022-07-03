/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:14:56 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/07 10:50:42 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			if (tmp->content)
				f(tmp->content);
			tmp = tmp->next;
		}
	}
}

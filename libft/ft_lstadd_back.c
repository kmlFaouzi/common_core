/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 08:22:25 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/07 14:35:45 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
			new = NULL;
		}
		else
		{
			tmp = *lst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
			tmp = NULL;
			new = NULL;
		}
	}
}

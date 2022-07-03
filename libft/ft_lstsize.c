/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 08:18:44 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/07 09:47:38 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	if (lst != NULL)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}

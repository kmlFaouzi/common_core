/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 08:26:10 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/07 10:44:32 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		free(lst);
	else if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:21:12 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/03 14:26:05 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*return_val;
	size_t	i;

	i = 0;
	return_val = (void *)malloc(count * size);
	if (!return_val)
		return (NULL);
	while ((char *)return_val && i < (count * size))
	{
		*(char *)(return_val + i) = 0;
		i++;
	}
	return (return_val);
}

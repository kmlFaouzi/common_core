/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:37:26 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/04 17:32:37 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*copy_s1;
	unsigned char	*copy_s2;
	size_t			i;

	i = 0;
	copy_s1 = (unsigned char *)s1;
	copy_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (copy_s1[i] != copy_s2[i])
			return (copy_s1[i] - copy_s2[i]);
		i++;
	}
	return (0);
}

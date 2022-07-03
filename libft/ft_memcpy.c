/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:12:27 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/04 17:49:51 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!d && !s)
		return (NULL);
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

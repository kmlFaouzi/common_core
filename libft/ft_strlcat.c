/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:27:48 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/05 08:01:09 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		return_value;
	size_t	size_dest;
	int		size_src;
	int		i;

	i = 0;
	size_dest = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size_dest >= size)
		return_value = size_src + size;
	else
		return_value = size_src + size_dest;
	while (src[i] && (size_dest + 1) < size)
		dst[size_dest++] = src[i++];
	dst[size_dest] = '\0';
	return (return_value);
}

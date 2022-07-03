/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:57:37 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/06 09:20:09 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size_needle;
	size_t	i;
	size_t	c;
	int		tmp;

	size_needle = ft_strlen(needle);
	if (needle == haystack || size_needle == 0 || !needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		c = 0;
		tmp = i;
		while (haystack[i] == needle[c] && c < size_needle && i < len)
		{
			c++;
			i++;
		}
		if (c == size_needle)
			return ((char *)(haystack + tmp));
		i = ++tmp;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:38:07 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/05 20:52:23 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		s_len = 1;
	else if (len > ft_strlen(s))
		s_len = ft_strlen(s) + 1;
	else
		s_len = len + 1;
	sub_str = (char *)malloc(s_len);
	if (!(sub_str))
		return (NULL);
	sub_str[--s_len] = '\0';
	while (s_len-- > 0)
		sub_str[s_len] = s[s_len + start];
	return (sub_str);
}

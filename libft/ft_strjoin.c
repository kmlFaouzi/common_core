/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:48:27 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/07 07:36:07 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1);
	i = ft_strlen(s2);
	size = i-- + j--;
	join = (char *)malloc(size + 1);
	if (!join)
		return (NULL);
	while (s2[i])
	{
		join[i + j + 1] = s2[i];
		i--;
	}
	while (s1[j])
	{
		join[j] = s1[j];
		j--;
	}
	join[size] = '\0';
	return (join);
}

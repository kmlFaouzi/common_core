/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:39:39 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/02 15:07:10 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strdup;
	int		i;

	i = ft_strlen(s1);
	strdup = (char *)malloc(i + 1);
	if (!strdup)
		return (NULL);
	while (i >= 0)
	{
		strdup[i] = s1[i];
		i--;
	}
	return (strdup);
}

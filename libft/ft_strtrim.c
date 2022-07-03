/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:34:23 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/06 19:50:58 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_strlen_trim(char const *s1, char const *set)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
	{
		i++;
		size--;
	}
	if (size <= 0)
		return (0);
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]))
	{
		i--;
		size--;
	}
	return (size);
}

char	*ft_strdup_trim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;
	int		k;

	trim = malloc(ft_strlen_trim(s1, set) + 1);
	if (!trim)
		return (NULL);
	k = 0;
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[j]))
		j--;
	if (i <= j)
	{
		while (i <= j)
			trim[k++] = s1[i++];
		trim[k] = '\0';
		return (trim);
	}
	trim[k] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	trim = ft_strdup_trim(s1, set);
	return (trim);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:32:38 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/03 14:23:02 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;

	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((cp_s1[i] == cp_s2[i] && cp_s1[i] != '\0') \
			&& (cp_s2[i] != '\0' && i < n))
		i++;
	if (i == n)
		i--;
	return (cp_s1[i] - cp_s2[i]);
}

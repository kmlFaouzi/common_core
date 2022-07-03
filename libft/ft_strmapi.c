/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:07:30 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/07 07:23:01 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char ))
{
	int		i;
	char	*mapi;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	mapi = (char *)malloc(i + 1);
	if (!mapi)
		return (NULL);
	mapi[i--] = '\0';
	while (i >= 0)
	{
		mapi[i] = f(i, s[i]);
		i--;
	}
	return (mapi);
}

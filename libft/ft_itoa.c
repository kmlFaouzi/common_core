/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:03:24 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/07 07:17:03 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_nbrlen(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	else if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	put_miness(long int *v, char *_case)
{
	if (*v < 0)
	{
		*_case = '-';
		*v *= -1;
	}
}

char	*ft_itoa(int n)
{
	char		*itoa;
	long int	tmp;
	int			size;

	tmp = n;
	size = ft_nbrlen(tmp);
	itoa = (char *)malloc(size + 1);
	if (!itoa)
		return (NULL);
	itoa[size--] = '\0';
	if (n == 0)
		itoa[size] = '0';
	else
	{
		put_miness(&tmp, &itoa[0]);
		while (tmp != 0)
		{
			itoa[size--] = tmp % 10 + '0';
			tmp /= 10;
		}
	}
	return (itoa);
}

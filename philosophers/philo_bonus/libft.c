/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:49:40 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/27 13:53:26 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*ft_itoa(int n)
{
	size_t			i;
	unsigned int	pow;
	unsigned int	nb;
	static char		*base = "0123456789";
	char			*word;

	i = n < 0;
	if (n < 0)
		nb = n;
	else
		nb = -n;
	word = malloc(sizeof(char) * (get_len(nb, &pow) + i + 1));
	if (!word)
		return (0);
	if (n < 0)
		word[0] = '-';
	while (pow >= 1)
	{
		word[i] = base[nb / pow];
		nb -= pow * (nb / pow);
		pow /= 10;
		i++;
	}
	word[i] = 0;
	return (word);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (0);
	while (s1[i])
	{
		join[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = 0;
	return (join);
}

unsigned int	get_len(unsigned int nb, unsigned int *pow)
{
	unsigned int	len;

	len = 1;
	*pow = 1;
	while (*pow <= nb / 10)
	{
		*pow *= 10;
		len++;
	}
	return (len);
}

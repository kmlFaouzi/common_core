/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:16:26 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/10 15:33:27 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_count_chaines(char const *s, char c)
{
	int	nb_chaines;
	int	i;

	if (!s)
		return (1);
	nb_chaines = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			nb_chaines++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	if (nb_chaines == (int )ft_strlen(s))
		nb_chaines = 1;
	return (nb_chaines);
}

char	*ft_strdup_split(char const *s, char c)
{
	int		i;
	char	*chaine;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	chaine = malloc(i + 1);
	if (!chaine)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		chaine[i] = s[i];
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}

void	_free(char **split)
{
	while (*split)
	{
		free(*split);
		split++;
	}
	free(split);
}

char	**under_split(char *s, char c, int nb_chaines)
{
	int		i;
	int		k;
	char	**split;

	split = (char **)malloc(sizeof(char *) * nb_chaines);
	if (!split)
		return (NULL);
	i = 0;
	k = 0;
	while (k < (nb_chaines - 1) && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		split[k] = ft_strdup_split(s + i, c);
		if (!split[k++])
		{
			_free(split);
			return (NULL);
		}
		while (s[i] != c && s[i])
			i++;
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		nb_chaines;

	if (!s)
		return (NULL);
	nb_chaines = ft_count_chaines(s, c) + 1;
	split = under_split((char *)s, c, nb_chaines);
	return (split);
}

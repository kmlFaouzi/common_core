/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:25:36 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/27 14:01:50 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

bool	only_numbers(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (false);
		i++;
	}
	return (true);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

unsigned int	pars_nbr(char *str)
{
	size_t			i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		nbr *= 10;
		nbr += str[i] - 48;
		i++;
	}
	return (nbr);
}

bool	check_args(int argc, char **argv, t_utils *pars)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11 || !only_numbers(argv[i])
			|| (ft_strlen(argv[i]) == 11
				&& ft_strcmp(argv[i], "42949667295") > 0))
			return (false);
		i++;
	}
	pars->nb_philo = pars_nbr(argv[1]);
	pars->tt_die = pars_nbr(argv[2]);
	pars->tt_eat = pars_nbr(argv[3]);
	pars->tt_sleep = pars_nbr(argv[4]);
	if (argc == 6)
		pars->nb_meals = pars_nbr(argv[5]);
	else
		pars->nb_meals = -1;
	if (!pars->nb_philo)
		return (false);
	return (true);
}

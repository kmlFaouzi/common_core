/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:25:36 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/25 09:26:46 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

int	ft_strchr(char c, char *str)
{
	int	exist;
	int	i;

	i = -1;
	exist = 0;
	while (str[++i])
		if (str[i] == c)
			exist = 1;
	return (exist);
}

int	ft_atoi(char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	sign = 1;
	while (ft_strchr(str[i], STR_ISSPACE))
		i++;
	if (str[i] == CHAR_MINES || str[i] == CHAR_PLUS)
	{
		if (str[i] == CHAR_MINES)
			sign = -1;
		i++;
	}
	nb = 0;
	while (str[i] >= STR_DIGITS[0] && str[i] <= STR_DIGITS[9])
	{
		nb = nb * 10 + str[i] - STR_DIGITS[0];
		i++;
	}
	return (nb * sign);
}

int	check_error(int ac, char **av)
{
	int	i;

	if (ac == 5 || ac == 6)
	{
		i = 0;
		if (ft_atoi(av[++i]) <= 0)
			return (printf(STR_ERROR2), 0);
	}
	else
		return (printf(STR_ERROR1), 0);
	return (1);
}
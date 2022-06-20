/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kml <kml@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:20:14 by kml               #+#    #+#             */
/*   Updated: 2022/06/20 15:58:36 by kml              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

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

void	insert_philo(t_info_philo *philo, int ac, char **av)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->tm_die = ft_atoi(av[2]);
	philo->tm_eat = ft_atoi(av[3]);
	philo->tm_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_meals = ft_atoi(av[5]);
}
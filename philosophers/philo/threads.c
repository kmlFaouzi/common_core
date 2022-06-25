/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:37:16 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/25 10:10:55 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->lunch);
	philo->last_meal = get_time();
	pthread_mutex_lock(philo->print);
	printf("%lums %zu is eating\n", get_ts(philo->ts), philo->name);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_unlock(&philo->lunch);
	ft_sleep(philo->infos->tm_eat);
	philo->nb_meals += 1;
	pthread_mutex_unlock(philo->fork[LEFT]);
	pthread_mutex_unlock(philo->fork[RIGHT]);
	return (*philo->stop != 1);
}

int	fall_asleep(t_philo *philo)
{
	if (*philo->stop == 1)
		return (0);
	pthread_mutex_lock(philo->print);
	printf("%lums %zu is sleeping\n", get_ts(philo->ts), philo->name);
	pthread_mutex_unlock(philo->print);
	ft_sleep(philo->infos->tm_sleep);
	if (*philo->stop == 1)
		return (0);
	pthread_mutex_lock(philo->print);
	printf("%lums %zu is thinking\n", get_ts(philo->ts), philo->name);
	pthread_mutex_unlock(philo->print);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->name % 2)
		ft_sleep(2);
	while (*philo->stop == 0)
	{
		if (!take_forks(philo, philo->fork[LEFT], philo->fork[RIGHT]))
			break ;
		if (!eat(philo))
			break ;
		if (!fall_asleep(philo))
			break ;
	}
	pthread_mutex_destroy(&philo->lunch);
	return (NULL);
}

void	set_philos(t_philo *philos, t_info_philo *infos,
	pthread_mutex_t *forks, pthread_mutex_t *prt)
{
	int	i;

	i = -1;
	while (++i < infos->nb_philo)
	{
		philos[i].name = i + 1;
		philos[i].nb_meals = 0;
		philos[i].infos = infos;
		philos[i].print = prt;
		pthread_mutex_init(&philos[i].lunch, NULL);
		get_forks(&philos[i], i, forks, infos->nb_philo);
	}
}

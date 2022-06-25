/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:30:23 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/25 08:41:41 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	launch_threads(t_info_philo *infos, pthread_mutex_t *forks, \
	pthread_mutex_t *prt)
{
	t_philo		*philos;
	int			i;
	t_timeval	tm;
	int			stop;

	i = 0;
	stop = 0;
	philos = malloc(sizeof(t_philo) * infos->nb_philo);
	if (!philos)
		return (0);
	set_philos(philos, infos, forks, prt);
	gettimeofday(&tm, NULL);
	while (i < infos->nb_philo)
	{
		philos[i].stop = &stop;
		philos[i].ts = tm;
		philos[i].last_meal = get_time();
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]))
			return (0);
		i++;
	}
	return (watch_threads(infos, philos, infos->nb_philo, forks));
}

int	watch_threads(t_info_philo *infos, t_philo *philos, \
	unsigned int nb_philos, pthread_mutex_t *forks)
{
	size_t	i;

	i = 0;
	while (*philos->stop == 0)
	{
		ft_sleep(4);
		check_death(philos, nb_philos);
		if (*philos->stop == 0 && infos->nb_meals > 0
			&& check_meals(philos, nb_philos, infos->nb_meals))
		{
			*philos->stop = 1;
			ft_sleep(5);
			printf("Everyone ate well\n");
		}
	}
	while (i < nb_philos)
	{
		if (i == 0 && *philos->stop == 1)
			unlock_forks(forks, nb_philos);
		if (pthread_join(philos[i].thread, NULL))
			return (0);
		i++;
	}
	free(philos);
	return (1);
}

int	is_dead(t_philo *philo)
{
	if (*philo->stop == 1)
		return (1);
	pthread_mutex_lock(&philo->lunch);
	if ((int)(get_time() - philo->last_meal) >= philo->infos->tm_die)
	{
		pthread_mutex_unlock(&philo->lunch);
		if (*philo->stop == 0)
		{
			*philo->stop = 1;
			pthread_mutex_lock(philo->print);
			printf("%lums %zu died\n", get_ts(philo->ts), philo->name);
			pthread_mutex_unlock(philo->print);
		}
		return (1);
	}
	pthread_mutex_unlock(&philo->lunch);
	return (0);
}

int	check_death(t_philo *philos, unsigned int nb_philos)
{
	size_t	i;

	i = 0;
	while (i < nb_philos)
	{
		if (is_dead(&philos[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_meals(t_philo *philos, unsigned int nb_philos, long nb_meals)
{
	size_t	i;

	i = 0;
	while (i < nb_philos)
	{
		if (philos[i].nb_meals < nb_meals)
			return (0);
		i++;
	}
	return (1);
}

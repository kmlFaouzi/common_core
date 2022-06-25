/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:04:39 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/25 08:18:27 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

pthread_mutex_t	*init_forks(t_info_philo philo)
{
	pthread_mutex_t	*forks;
	int				i;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * philo.nb_philo);
	if (!forks)
		return (NULL);
	while (++i < philo.nb_philo)
		pthread_mutex_init(forks + i, NULL);
	return (forks);
}

void	destroy_forks(pthread_mutex_t *forks, t_info_philo philo)
{
	int	i;

	i = -1;
	while (++i < philo.nb_philo)
		pthread_mutex_destroy(forks + i);
	free(forks);
}

int	take_forks(t_philo *philo, pthread_mutex_t *forkl,
	pthread_mutex_t *forkr)
{
	if (*philo->stop == 1)
		return (0);
	pthread_mutex_lock(forkl);
	if (*philo->stop == 1)
		return (0);
	pthread_mutex_lock(philo->print);
	printf("%lums %zu has taken a fork\n", get_ts(philo->ts), philo->name);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(forkr);
	if (*philo->stop == 1)
		return (0);
	pthread_mutex_lock(philo->print);
	printf("%lums %zu has taken a fork\n", get_ts(philo->ts), philo->name);
	pthread_mutex_unlock(philo->print);
	return (1);
}

void	get_forks(t_philo *philo, size_t index, pthread_mutex_t *forks,
	unsigned int nb_philo)
{
	if (index == 0)
	{
		philo->fork[LEFT] = &forks[nb_philo - 1];
		philo->fork[RIGHT] = &forks[0];
	}
	else
	{
		philo->fork[LEFT] = &forks[index - 1];
		philo->fork[RIGHT] = &forks[index];
	}
}

void	unlock_forks(pthread_mutex_t *forks, unsigned int nb_philos)
{
	size_t	i;

	i = 0;
	while (i < nb_philos)
		pthread_mutex_unlock(&forks[i++]);
}

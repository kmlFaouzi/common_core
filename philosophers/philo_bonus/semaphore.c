/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:57:58 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/27 14:08:54 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

sem_t	*init_forks(t_utils *utils)
{
	sem_t	*forks;

	sem_unlink("forks");
	forks = sem_open("forks", O_CREAT, S_IRWXU | S_IRWXG, utils->nb_philo);
	return (forks);
}

int	take_forks(t_philo *philo)
{
	if (*philo->stop == true)
		return (0);
	sem_wait(philo->forks);
	if (*philo->stop == true)
		return (0);
	sem_wait(philo->print);
	printf("%lums %zu has taken a fork\n", get_ts(philo->ts), philo->name);
	sem_post(philo->print);
	sem_wait(philo->forks);
	if (*philo->stop == true)
		return (0);
	sem_wait(philo->print);
	printf("%lums %zu has taken a fork\n", get_ts(philo->ts), philo->name);
	sem_post(philo->print);
	return (1);
}

void	kill_children(t_philo *philos, unsigned int nb_philos)
{
	size_t	i;

	i = 0;
	while (i < nb_philos)
	{
		kill(philos[i].pid, SIGKILL);
		i++;
	}
	i = 0;
	while (i < nb_philos)
	{
		sem_close(philos[i].lunch);
		sem_unlink(philos[i].lunch_name);
		free(philos[i].lunch_name);
		i++;
	}
}

int	eat(t_philo *philo)
{
	sem_wait(philo->lunch);
	philo->last_meal = get_time();
	sem_wait(philo->print);
	printf("%lums %zu is eating\n", get_ts(philo->ts), philo->name);
	sem_post(philo->print);
	sem_post(philo->lunch);
	ft_sleep(philo->utils->tt_eat);
	philo->nb_meals += 1;
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (*philo->stop == true)
		return (0);
	return (1);
}

int	fall_asleep(t_philo *philo)
{
	if (*philo->stop == true)
		return (0);
	sem_wait(philo->print);
	printf("%lums %zu is sleeping\n", get_ts(philo->ts), philo->name);
	sem_post(philo->print);
	ft_sleep(philo->utils->tt_sleep);
	if (*philo->stop == true)
		return (0);
	sem_wait(philo->print);
	printf("%lums %zu is thinking\n", get_ts(philo->ts), philo->name);
	sem_post(philo->print);
	return (1);
}

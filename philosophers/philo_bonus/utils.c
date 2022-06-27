/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:00:28 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/27 14:00:58 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

size_t	get_time(void)
{
	struct timeval	tp;
	size_t			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	ft_sleep(size_t ms)
{
	size_t	curr;
	size_t	end;

	curr = get_time();
	end = curr + ms;
	while (get_time() < end)
		usleep(100);
}

unsigned long	get_ts(struct timeval ts)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((unsigned long)(tv.tv_sec * 1000 + tv.tv_usec / 1000)
			- (ts.tv_sec * 1000 + ts.tv_usec / 1000));
}

int	is_dead(t_philo *philo)
{
	if (*philo->stop == true)
		return (1);
	sem_wait(philo->lunch);
	if (get_time() - philo->last_meal >= philo->utils->tt_die)
	{
		sem_post(philo->lunch);
		if (*philo->stop == false)
		{
			*philo->stop = true;
			sem_wait(philo->print);
			printf("%lums %zu died\n", get_ts(philo->ts), philo->name);
		}
		return (1);
	}
	sem_post(philo->lunch);
	return (0);
}

void	unlock_sync(sem_t *sync, unsigned int nb_philos)
{
	size_t	i;

	i = 0;
	while (i < nb_philos)
	{
		sem_post(sync);
		i++;
	}
}

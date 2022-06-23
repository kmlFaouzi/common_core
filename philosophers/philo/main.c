/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kml <kml@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:56:36 by kml               #+#    #+#             */
/*   Updated: 2022/06/20 15:59:12 by kml              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t *init_forks(t_info_philo philo)
{
	pthread_mutex_t *forks;
	int i;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * philo.nb_philo);
	if (!forks)
		return (NULL);
	while (++i < philo.nb_philo)
		pthread_mutex_init(forks + i, NULL);
	return (forks);
}

void destroy_forks(pthread_mutex_t *forks, t_info_philo philo)
{
	int i;

	i = -1;
	while (++i < philo.nb_philo)
		pthread_mutex_destroy(forks + i);
	free(forks);
}

size_t get_time(void)
{
	struct timeval tp;
	size_t milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

unsigned long get_ts(struct timeval ts)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((unsigned long)(tv.tv_sec * 1000 + tv.tv_usec / 1000) - (ts.tv_sec * 1000 + ts.tv_usec / 1000));
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

int take_forks(t_philo *philo, pthread_mutex_t *forkl,
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

int eat(t_philo *philo)
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

int fall_asleep(t_philo *philo)
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

void *routine(void *arg)
{
	t_philo *philo;

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

void get_forks(t_philo *philo, size_t index, pthread_mutex_t *forks,
			   unsigned int nb_philo)
{
	if (nb_philo == 1)
	{
		philo->fork[LEFT] = &forks[0];
		philo->fork[RIGHT] = &forks[0];
	}
	else if (index == 0)
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

void set_philos(t_philo *philos, t_info_philo *infos,
				pthread_mutex_t *forks, pthread_mutex_t *prt)
{
	int i;

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

void	unlock_forks(pthread_mutex_t *forks, unsigned int nb_philos)
{
	size_t	i;

	i = 0;
	while (i < nb_philos)
		pthread_mutex_unlock(&forks[i++]);
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

int	watch_threads(t_info_philo *infos, t_philo *philos, unsigned int nb_philos,
			pthread_mutex_t *forks)
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

int launch_threads(t_info_philo *infos, pthread_mutex_t *forks,
					pthread_mutex_t *prt)
{
	t_philo *philos;
	int i;
	t_timeval tm;
	int stop;

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

int main(int ac, char **av)
{
	t_info_philo infos;
	pthread_mutex_t *forks;
	pthread_mutex_t prt;

	if (!check_error(ac, av))
		return (0);
	insert_philo(&infos, ac, av);
	forks = init_forks(infos);
	if (!forks)
		return (0);
	pthread_mutex_init(&prt, NULL);
	launch_threads(&infos, forks, &prt);
	destroy_forks(forks, infos);
	pthread_mutex_destroy(&prt);
	return (0);
}

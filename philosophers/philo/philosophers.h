/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:59:50 by kml               #+#    #+#             */
/*   Updated: 2022/06/25 08:40:25 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include<stdio.h>
# include<pthread.h>
# include<sys/time.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct timeval	t_timeval;

typedef struct s_info_philo
{
	int	nb_philo;
	int	tm_eat;
	int	tm_sleep;
	int	tm_die;
	int	nb_meals;
}t_info_philo;

typedef struct s_philo
{
	size_t			name;
	int				*stop;
	long			nb_meals;
	t_info_philo	*infos;
	pthread_mutex_t	*fork[2];
	pthread_mutex_t	*print;
	pthread_mutex_t	lunch;
	size_t			last_meal;
	struct timeval	ts;
	pthread_t		thread;
}	t_philo;
# define LEFT 0
# define RIGHT 1
# define STR_ISSPACE "\t\n\v\f\r "
# define STR_DIGITS "0123456789"
# define STR_ERROR1 "you have to enter 5 or 6 paramaters\n"
# define STR_ERROR2 "you have to enter a positive numbers!\n"
# define CHAR_PLUS '+'
# define CHAR_MINES '-'

int				check_error(int ac, char **av);
void			insert_infos(t_info_philo *philo, int ac, char **av);
int				ft_atoi(char *str);
int				ft_strchr(char c, char *str);
pthread_mutex_t	*init_forks(t_info_philo philo);
void			destroy_forks(pthread_mutex_t *forks, t_info_philo philo);
int				take_forks(t_philo *philo, pthread_mutex_t *forkl, \
	pthread_mutex_t *forkr);
void			get_forks(t_philo *philo, size_t index, \
	pthread_mutex_t *forks, unsigned int nb_philo);
void			unlock_forks(pthread_mutex_t *forks, unsigned int nb_philos);
size_t			get_time(void);
unsigned long	get_ts(struct timeval ts);
void			ft_sleep(size_t ms);
int				launch_threads(t_info_philo *infos, pthread_mutex_t *forks, \
	pthread_mutex_t *prt);
int				watch_threads(t_info_philo *infos, t_philo *philos, \
	unsigned int nb_philos, pthread_mutex_t *forks);
int				is_dead(t_philo *philo);
int				check_death(t_philo *philos, unsigned int nb_philos);
int				check_meals(t_philo *philos, unsigned int nb_philos, \
	long nb_meals);
int				eat(t_philo *philo);
int				fall_asleep(t_philo *philo);
void			*routine(void *arg);
void			set_philos(t_philo *philos, t_info_philo *infos, \
	pthread_mutex_t *forks, pthread_mutex_t *prt);
#endif
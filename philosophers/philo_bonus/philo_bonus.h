/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:14:33 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/27 14:09:40 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H

# define PHILO_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <signal.h>

# define STR_ISSPACE "\t\n\v\f\r "
# define STR_DIGITS "0123456789"
# define STR_ERROR1 "you have to enter 5 or 6 paramaters\n"
# define STR_ERROR2 "you have to enter a positive numbers!\n"
# define CHAR_PLUS '+'
# define CHAR_MINES '-'
# define ERR 2
# define IS_DEAD 0
# define ATE_ENOUGH 1

typedef struct s_utils
{
	unsigned int	nb_philo;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	long			nb_meals;
}	t_utils;

typedef struct s_philo
{
	size_t			name;
	long			nb_meals;
	bool			*stop;
	t_utils			*utils;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*lunch;
	sem_t			*sync;
	char			*lunch_name;
	size_t			last_meal;
	struct timeval	ts;
	int				pid;
}	t_philo;

bool			check_args(int argc, char **argv, t_utils *pars);
char			*ft_itoa(int n);
int				ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
unsigned int	get_len(unsigned int nb, unsigned int *pow);
size_t			get_time(void);
void			ft_sleep(size_t ms);
unsigned long	get_ts(struct timeval ts);
int				is_dead(t_philo *philo);
void			unlock_sync(sem_t *sync, unsigned int nb_philos);
int				launch_children(t_utils *utils, sem_t *print);
int				watch_children(t_philo *philos, unsigned int nb_philos);
void			process(t_philo *philo);
void			*live(void *arg);
int				set_philos(t_philo *philos, t_utils *utils, sem_t *print);
int				fall_asleep(t_philo *philo);
int				eat(t_philo *philo);
void			kill_children(t_philo *philos, unsigned int nb_philos);
int				take_forks(t_philo *philo);
sem_t			*init_forks(t_utils *utils);
#endif
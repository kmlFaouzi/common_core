/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:14:33 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/25 09:27:08 by kfaouzi          ###   ########.fr       */
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

int	check_error(int ac, char **av);
#endif
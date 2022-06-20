/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kml <kml@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:59:50 by kml               #+#    #+#             */
/*   Updated: 2022/06/20 15:56:52 by kml              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILISOPHERS
#include<stdio.h>
typedef struct s_info_philo
{
	int	nb_philo;
	int	tm_eat;
	int	tm_sleep;
	int	tm_die;
	int	nb_meals;
}t_info_philo;

# define PHILISOPHERS
# define STR_ISSPACE "\t\n\v\f\r "
# define STR_DIGITS "0123456789"
# define STR_ERROR1 "you have to enter 5 or 6 paramaters\n"
# define STR_ERROR2 "you have to enter a positive numbers!\n"
# define CHAR_PLUS '+'
# define CHAR_MINES '-'

int		check_error(int ac, char **av);
void	insert_philo(t_info_philo *philo, int ac, char **av);
int		ft_atoi(char *str);
int		ft_strchr(char c, char *str);

#endif
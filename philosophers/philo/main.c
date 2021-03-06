/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:56:36 by kml               #+#    #+#             */
/*   Updated: 2022/06/25 09:05:00 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_info_philo	infos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	prt;

	if (!check_error(ac, av))
		return (0);
	insert_infos(&infos, ac, av);
	forks = init_forks(infos);
	if (!forks)
		return (0);
	pthread_mutex_init(&prt, NULL);
	launch_threads(&infos, forks, &prt);
	destroy_forks(forks, infos);
	pthread_mutex_destroy(&prt);
	return (0);
}

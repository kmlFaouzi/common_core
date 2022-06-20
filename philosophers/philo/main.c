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

#include"philosophers.h"

int	main(int ac, char **av)
{
	int				valid;
	t_info_philo	philo;

	valid = check_error(ac, av);
	if(!valid)
		return (0);
	insert_philo(&philo, ac, av);
}
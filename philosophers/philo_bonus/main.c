/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:22:18 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/06/27 14:01:39 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

int	main(int ac, char **av)
{
	sem_t			*print;
	t_utils			utils;

	if (ac < 5 || ac > 6 || !check_args(ac, av, &utils))
	{
		write(2, "Wrong arguments\n", 16);
		return (0);
	}
	if (!utils.nb_meals)
	{
		printf("Everyone ate well, even though no one ate\n");
		return (0);
	}
	sem_unlink("print");
	print = sem_open("print", O_CREAT, S_IRWXU | S_IRWXG, 1);
	launch_children(&utils, print);
	sem_close(print);
	sem_unlink("print");
	return (0);
}

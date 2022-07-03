/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:41:50 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/07 07:34:22 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		rest;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	rest = nbr % 10 + '0';
	nbr /= 10;
	if (nbr != 0)
		ft_putnbr_fd(nbr, fd);
	write(fd, &rest, 1);
}

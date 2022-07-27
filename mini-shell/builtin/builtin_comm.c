/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitin_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:28:12 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/07/26 18:48:06 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, str + i, 1);
	return (i - 1);
}
int	exist_n_echo(char *arg, char beg, char end)
{
	int	i;

	i = -1;
	if (arg[++i] != beg)
		return (0);
	while (arg[++i])
		if (arg[i] != end)
			return (0);
	return (1);
}

int	ft_skip_nwln(char **command)
{
	int	skip;
	
	skip = 0;
	while (exist_n_echo(command[skip + 1], '-', 'n'))
		skip++;
	return (skip);
}

int ft_echo(char **command)
{
	int	i;
	int	nwln;

	nwln = ft_skip_nwln(command);
	i = ft_skip_nwln(command);
	while (command[++i])
	{
		ft_putstr(command[i]);
		if (command[i + 1])
			ft_putstr(" ");
	}
	if (!nwln)
		ft_putstr("\n");
	return (1);
}

int main(int ac, char **av)
{
	ft_echo(av);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:23:14 by mbueno            #+#    #+#             */
/*   Updated: 2023/03/14 14:51:26 by mbueno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"


static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || \
			c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	long	nbr;
	long	sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]) && nptr[i] != '\0')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] != '\0' && ('0' <= nptr[i] && nptr[i] <= '9'))
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (sign * nbr);
}

void	ft_send(int pid, int c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(5);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Wrong amount of arguments!");
		return (1);
	}
	else
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			ft_send(pid, av[2][i]);
			i++;
		}
		ft_send(pid, '\n');
	}
	return (0);
}

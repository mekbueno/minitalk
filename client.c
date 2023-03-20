/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:23:14 by mbueno            #+#    #+#             */
/*   Updated: 2023/03/17 11:20:56 by mbueno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	long	num;
	long	sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] != '\0' && str[i] >= 32 && str[i] == 127)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && ('0' <= str[i] && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (sign * num);
}

void	ft_sigsender(int pid, int singleChar)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((singleChar & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
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
		ft_printf("Invalid Input. Please check again.");
		return (1);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		ft_sigsender(pid, av[2][i]);
		i++;
	}
	ft_sigsender(pid, '\n');
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:23:24 by mbueno            #+#    #+#             */
/*   Updated: 2023/03/17 11:23:49 by mbueno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	ft_sigreceiver(int incomingSig)
{
	static int	bit;
	static int	c;

	if (incomingSig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Invalid Input. Please check again.");
		return (1);
	}
	pid = getpid();
	ft_printf("PID = [ %i ]\n", pid);
	while (1)
	{
		signal(SIGUSR1, ft_sigreceiver);
		signal(SIGUSR2, ft_sigreceiver);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:23:24 by mbueno            #+#    #+#             */
/*   Updated: 2023/03/14 14:36:31 by mbueno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"

void    ft_handle(int signal)
{
    static int    bit;
    static int    c;

    if (signal == SIGUSR1)
        c |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", c);
        bit = 0;
        c = 0;
    }
}

int    main(int ac, char **av)
{
    int    pid;

    (void)av;
    if (ac != 1)
    {
        ft_printf("Wrong amount of arguments!");
        return (1);
    }
    else
    {
        pid = getpid();
        ft_printf("PID = %i\n", pid);
    }
    while (1)
    {
        signal(SIGUSR1, ft_handle);
        signal(SIGUSR2, ft_handle);
        pause();
    }
    return (0);
}

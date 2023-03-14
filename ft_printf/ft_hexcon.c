/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexcon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:44:46 by mbueno            #+#    #+#             */
/*   Updated: 2022/11/15 15:04:35 by mbueno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_convert(size_t nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_hex_convert(nb / 16, base);
	}
	count += ft_putchar((char)(base[nb % 16]));
	return (count);
}

int	ft_put_hex(unsigned long long nb, char *base)
{
	return (ft_hex_convert(nb, base));
}

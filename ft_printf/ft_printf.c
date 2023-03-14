/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:53:48 by mbueno            #+#    #+#             */
/*   Updated: 2023/03/14 14:06:22 by mbueno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_type_ident(char c, va_list args)
{
	unsigned long long	p;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, int)));
	else if (c == 'x')
		return (ft_put_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
	{
		p = va_arg(args, long long);
		if (p == 0)
			return (ft_putstr("(nil)"));
		else
			return (ft_putstr("0x") + ft_put_hex(p, "0123456789abcdef"));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (format == 0)
		return (0);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 0)
				break ;
			len += ft_type_ident(format[i], args);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	char	txt[] = "Hello world!";
	char	c = 'm';
	int		zahl = 15;
	int		*ptr = &zahl;
	int		size = 0;
	char	*str = "hi";

	ft_printf("\n");
	//printf("%p", 0);

	printf("42 FT_PRINTF //\n\n");
	ft_printf("\n");

	ft_printf("Test [c]: %c\n", c);
	ft_printf("Test [s]: %s\n", txt);
	ft_printf("Test [p]: %p | %p\n", &ptr, 0);
	ft_printf("Test [d]: %d\n", zahl);
	ft_printf("Test [i]: %i\n", zahl);
	ft_printf("Test [u]: %u\n", zahl);
	ft_printf("Test [x]: %x\n", zahl);
	ft_printf("Test [X]: %X\n", zahl);
	ft_printf("Test [%%]: %%%s\n");
	printf("\n\n\"");
	
	size = ft_printf("senad test: %i\n", size);
	ft_printf("%i\n", size);
	size = printf("senad test: %i\n", size);
	printf("%i\n", size);

	

	printf("\n");
	printf("\n");

	printf("PRINTF //\n\n");
	printf("\n");

	printf("Test [c]: %c\n", c);
	printf("Test [s]: %s\n", txt);
	printf("Test [p]: %p |\n", &ptr);
	printf("Test [d]: %d\n", zahl);
	printf("Test [i]: %i\n", zahl);
	printf("Test [u]: %u\n", zahl);
	printf("Test [x]: %x\n", zahl);
	printf("Test [X]: %X\n", zahl);
	printf("Test [%%]: %%%s");
	printf("\n");

}
*/

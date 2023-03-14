# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbueno <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 10:13:23 by mbueno            #+#    #+#              #
#    Updated: 2023/03/14 14:08:09 by mbueno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRC =	ft_printf.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putnbr.c\
	ft_putnbr_u.c\
	ft_hexcon.c\
		
OBJECTS = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = cc

all:
	cc $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJECTS)

$(NAME): all

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re

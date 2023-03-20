# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbueno <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 15:29:51 by mbueno            #+#    #+#              #
#    Updated: 2023/03/16 11:50:17 by mbueno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVERSRC	=	server.c
CLIENTSRC    =	client.c

SERVEROBJS    =    $(SSRC:.c=.o)
CLIENTOBJS    =    $(CSRC:.c=.o)

CC        =    cc
CFLAGS    =    -Wall -Wextra -Werror

SERVER = server
CLIENT = client

FTPRINTF = ft_printf/ft_printf.a
FTPRINTF_PATH = ft_printf/

all: printf $(SERVER) $(CLIENT)

printf:
	make -C $(FTPRINTF_PATH) all

$(SERVER):
	$(CC) -o $(SERVER) $(CFLAGS) $(SERVERSRC) $(FTPRINTF)

$(CLIENT):
	$(CC) -o $(CLIENT) $(CFLAGS) $(CLIENTSRC) $(FTPRINTF)


clean:
	rm -f $(SERVEROBJS) $(CLIENTOBJS)
	make -C $(FTPRINTF_PATH) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(FTPRINTF_PATH) fclean

re:	fclean all

.PHONY:	all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbueno <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 15:29:51 by mbueno            #+#    #+#              #
#    Updated: 2023/03/14 14:37:51 by mbueno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SSRC	=	server.c
CSRC    =	client.c

SOBJS    =    $(SSRC:.c=.o)
COBJS    =    $(CSRC:.c=.o)

CC        =    cc
RM        =    rm -f
CFLAGS    =    -Wall -Wextra -Werror

SERVER = server
CLIENT = client

FTPRINTF = ft_printf/ft_printf.a

all: $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) -o $(SERVER) $(CFLAGS) $(SSRC) $(FTPRINTF)

$(CLIENT):
	$(CC) -o $(CLIENT) $(CFLAGS) $(CSRC) $(FTPRINTF)

clean:
	@$(RM) $(SOBJS) $(COBJS)

fclean: clean
	@$(RM) $(SERVER) $(CLIENT)

re:	fclean all

.PHONY:	all clean fclean re

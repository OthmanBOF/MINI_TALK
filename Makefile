# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 17:05:46 by obouftou          #+#    #+#              #
#    Updated: 2025/02/06 16:51:28 by obouftou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SEVER_NAME = server
CLIENT_SRC = client.c minitalk_utils.c
SEVER_SRC = server.c minitalk_utils.c
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDE = minitalk.h
CC = cc
OBJ_S = ${SEVER_SRC:.c=.o}
OBJ_C = ${CLIENT_SRC:.c=.o}

all: $(SEVER_NAME) $(CLIENT_NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(SEVER_NAME): $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(SEVER_NAME)

$(CLIENT_NAME): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(CLIENT_NAME)

clean:
	$(RM) $(OBJ_C) $(OBJ_S)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SEVER_NAME)

re: fclean all

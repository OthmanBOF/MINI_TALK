# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 17:05:46 by obouftou          #+#    #+#              #
#    Updated: 2025/02/12 14:37:10 by obouftou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SEVER_NAME = server
SEVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus
CLIENT_SRC = client.c minitalk_utils.c
SEVER_SRC = server.c minitalk_utils.c
CLIENT_BONUS_SRC = client_bonus.c minitalk_utils.c
SEVER_BONUS_SRC = server_bonus.c minitalk_utils.c
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDE = minitalk.h
CC = cc
OBJ_S = ${SEVER_SRC:.c=.o}
OBJ_C = ${CLIENT_SRC:.c=.o}
OBJ_BONUS_C = ${CLIENT_BONUS_SRC:.c=.o}
OBJ_BONUS_S = ${SEVER_BONUS_SRC:.c=.o}

all: $(SEVER_NAME) $(CLIENT_NAME)

bonus: $(SEVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(SEVER_NAME): $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(SEVER_NAME)

$(CLIENT_NAME): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(CLIENT_NAME)

$(SEVER_BONUS_NAME): $(OBJ_BONUS_S)
	$(CC) $(CFLAGS) $(OBJ_BONUS_S) -o $(SEVER_BONUS_NAME)

$(CLIENT_BONUS_NAME): $(OBJ_BONUS_C)
	$(CC) $(CFLAGS) $(OBJ_BONUS_C) -o $(CLIENT_BONUS_NAME)

clean:
	$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_BONUS_C) $(OBJ_BONUS_S)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SEVER_NAME) $(CLIENT_BONUS_NAME) $(SEVER_BONUS_NAME)

re: fclean all

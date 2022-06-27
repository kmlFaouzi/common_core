# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 14:03:08 by kfaouzi           #+#    #+#              #
#    Updated: 2022/06/27 14:05:31 by kfaouzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c libft.c parser.c process.c semaphore.c utils.c
OBJS = $(SRCS:%.c=%.o)
NAME = philo
FLAG_TREAD = -lpthread
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
INC = philosphers.h

all:$(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $^
%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $(SRCS) -o $(OBJS)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
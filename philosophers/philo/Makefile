# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kml <kml@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:18:05 by kml               #+#    #+#              #
#    Updated: 2022/06/20 16:00:22 by kml              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c parser.c
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
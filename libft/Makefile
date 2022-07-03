# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 06:49:00 by kfaouzi           #+#    #+#              #
#    Updated: 2021/11/12 03:19:15 by kfaouzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_itoa.c ft_memmove.c ft_strjoin.c ft_tolower.c ft_memset.c ft_strlcat.c \
		  ft_toupper.c ft_atoi.c ft_putchar_fd.c ft_strlcpy.c ft_bzero.c ft_putendl_fd.c \
		  ft_strlen.c ft_calloc.c ft_putnbr_fd.c ft_strmapi.c ft_isalnum.c ft_putstr_fd.c \
		  ft_strncmp.c ft_isalpha.c ft_split.c ft_strnstr.c ft_isascii.c ft_memchr.c ft_strchr.c \
		  ft_strrchr.c ft_isdigit.c ft_memcmp.c ft_strdup.c ft_strtrim.c ft_isprint.c ft_memcpy.c \
		  ft_striteri.c ft_substr.c  \

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BNS = $(BONUS:.c=.o)

%.o : %.c libft.h
	gcc -Wall -Werror -Wextra -I. -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(OBJECTS_BNS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

bonus: $(NAME) $(OBJECTS_BNS)
	ar rc  $^
.PHONY: bonus all clean fclean re

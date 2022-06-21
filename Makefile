# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 12:58:07 by arafeeq           #+#    #+#              #
#    Updated: 2022/06/05 12:37:27 by arafeeq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c print_char.c print_number.c print_hexa.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

AR = ar rcs

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
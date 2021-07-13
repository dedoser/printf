# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 01:35:10 by ehillman          #+#    #+#              #
#    Updated: 2020/11/22 17:25:02 by fignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =  	description.c	ft_itoa.c	print_int.c	print_str.c\
		ft_atoi.c	ft_printf.c	ft_putstr_fd.c	print_char.c\
		print_percent.c	print_uns.c	check_str.c	ft_isdigit.c\
		ft_strlen.c	print_hex.c	print_pointer.c	\
		work_with_var.c

OBJS = $(SRC:.c=.o)
LIB = ar rcs

all:	$(NAME)

$(NAME): $(OBJS)
		$(LIB) $(NAME) $(OBJS)
		ranlib $(NAME)
clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f libftprintf.a

re:		fclean all

.PHONY:	all, clean, fclean, re

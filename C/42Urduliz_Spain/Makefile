# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/24 12:38:25 by vsobolev          #+#    #+#              #
#    Updated: 2026/09/24 12:38:30 by vsobolev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TASK
#• Create the Makefile that’ll compile your libft.a.
#• The Makefile will get its source files from the "srcs" directory.
#• The Makefile will get its header files from the "includes" directory.
#• The lib will be at the root of the exercise.
#• The Makefile should also implement the following rules: clean, fclean and re as
#well as all.
#• fclean does the equivalent of a make clean and also erases the binary created
#during the make. re does the equivalent of a make fclean followed by a make.
#• We’ll only fetch your Makefile and test it with our files. For this exercise, only
#the following 5 mandatory functions of your lib have to be handled : (ft_putchar,
#ft_putstr, ft_strcmp, ft_strlen and ft_swap).

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes

MY_SOURCES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
MY_OBJECTS = $(MY_SOURCES:srcs/%.c=%.o)

all: $(NAME)

$(NAME):
	$(CC) -c $(MY_SOURCES) -I $(INCLUDES)
	ar rc $(NAME) $(MY_OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

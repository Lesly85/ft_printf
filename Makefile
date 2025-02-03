# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leslyescobar <leslyescobar@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 20:42:55 by lesescob          #+#    #+#              #
#    Updated: 2025/02/03 05:29:12 by leslyescoba      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
flags = -Wall -Werror -Wextra -Iincludes
NAME = sources/libftprintf.a
EXEC = test_ft_printf
SRC = ft_printf.c ft_putchar.c ft_putnumb.c ft_putstr.c\
		ft_unsigned.c ft_puthexa_x.c ft_puthexa_XX.c \
		ft_putptr.c

OBJECTS = $(addprefix ./sources/, $(SRC:.c=.o))

all : $(NAME)

$(NAME): $(OBJECTS)
		@ar rc $(NAME) $(OBJECTS)

%.o: %.c
		$(CC) -c  $(flags) $< -o $@

clean:
		@rm -rf $(OBJECTS)

fclean: clean
		@rm -rf $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re

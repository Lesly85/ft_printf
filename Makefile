# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 20:42:55 by lesescob          #+#    #+#              #
#    Updated: 2025/02/04 17:38:39 by lesescob         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
flags = -Wall -Werror -Wextra -Iincludes
NAME = libftprintf.a
SRC = ft_printf.c ft_putchar.c ft_putnumb.c ft_putstr.c\
		ft_unsigned.c ft_puthexa_x.c ft_puthexa_upper.c\
		ft_putptr.c

OBJECTS = $(addprefix ./sources/, $(SRC:.c=.o))

all : $(NAME)

$(NAME): $(OBJECTS)
		@ar rc $(NAME) $(OBJECTS)

%.o: %.c
		@$(CC) -c  $(flags) $< -o $@

clean:
		@rm -rf $(OBJECTS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

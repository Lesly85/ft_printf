# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 20:42:55 by lesescob          #+#    #+#              #
#    Updated: 2024/12/20 20:56:08 by lesescob         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
flags = -Wall -Werror -Wextra
NAME = libft.a
SRC =

OBJECTS = ${SRC: .c=.o}

all : $(NAME)

$(NAME):$(OBJECTS)
		ar rc $(NAME) $(OBJECTS)

%.o: %.c
		${CC} -c  ${flags} -I. $< -o $@

clean:
		rm -rf $(OBJECTS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

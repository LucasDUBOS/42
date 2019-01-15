#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:17:36 by lucdubos          #+#    #+#              #
#    Updated: 2017/11/07 15:17:49 by lucdubos         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

PATH = SRCS

PATH1 = includes

SRC =	$(PATH)/ft_putchar.c\
		$(PATH)/ft_putstr.c\
		$(PATH)/ft_strcmp.c\
		$(PATH)/ft_strlen.c\
		$(PATH)/ft_swap.c

OB = 	ft_putchar.o\
		ft_putstr.o\
		ft_strcmp.o\
		ft_strlen.o\
		ft_swap.o

OBJ =	$(SRC:.c=.o)

all:	$(OBJ) $(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) $(OB)

clean:
	rm -f $(OB)

fclean: clean
	rm -f $(NAME)

re: fclean all
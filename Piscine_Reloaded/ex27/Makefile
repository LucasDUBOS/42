#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:48:46 by lucdubos          #+#    #+#              #
#    Updated: 2017/11/07 15:52:15 by lucdubos         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_display_file

SRC =	main.c

OBJ =	$(SRC:.c=.o)

all:	$(OBJ) $(NAME)

$(NAME):
	cc -Wall -Werror -Wextra -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 15:15:38 by lucdubos          #+#    #+#              #
#    Updated: 2018/09/18 11:48:39 by lucdubos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

SRCS = ./analyse.c\
	   ./attributs.c\
	   ./conversion.c\
	   ./ft_printf.c\
	   ./get_info.c\
	   ./largeur_champs.c\
	   ./precision.c

RM = rm -f

OBJS = $(SRCS:.c=.o)

CURRENT_DIR = $(shell pwd)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	@echo 'COMPILATION LIBFT'
	@make -C libft

$(NAME): $(OBJS) $(LIBFT)
	@echo 'CREATION .o PRINTF'
	@$(CC) -c $(FLAGS) $(SRCS)
	@echo "COPIE libft.a DANS DOSSIER COURANT"
	@cp libft/libft.a ./$(NAME)
	@echo 'ASSEMBLAGE .o PRINTF'
	@ar rc $(NAME) $(OBJS)
	@echo 'INDEXATION PRINTF'
	@ranlib $(NAME)

clean:
	@echo 'SUPPRESSION .o PRINTF'
	@$(RM) $(OBJS)
	@cd ./libft/ && make clean

fclean: clean
	@echo 'SUPPRESSION .a PRINTF'
	@$(RM) $(NAME)
	@cd ./libft/ && make fclean

re: fclean all

curqi: re
	@cp *.a ~/Desktop/42/curqi_test/
	@cd ~/Desktop/42/curqi_test/ && make && ./ft_printf_tests
	@cd $(CURRENT_DIR)


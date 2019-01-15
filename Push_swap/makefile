## **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 15:15:38 by lucdubos          #+#    #+#              #
#    Updated: 2018/10/24 17:08:32 by lucdubos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_C = checker

LIBFT = ./commun/libft/libft.a

SRCS =				./pushswap/algo.c\
					./pushswap/algo1.c\
					./pushswap/option.c\
					./commun/depil_b.c\
					./commun/ft_petit_nbr6.c\
					./commun/gestion_erreur.c\
					./commun/rarbrr.c\
					./commun/stock_print.c\
					./commun/ft_depil_sens.c\
					./commun/ft_push_b_1.c\
					./commun/papb.c\
					./commun/rrarrbrrr.c\
					./commun/tri_mediane.c\
					./commun/ft_petit_nbr.c\
					./commun/ft_rot_sens.c\
					./commun/placement.c\
					./commun/sasbss.c\
					./pushswap/main_pushswap.c\
					./checker_push/main_checker.c\

SRCS_P =			./pushswap/algo.c\
					./pushswap/algo1.c\
					./pushswap/option.c\
					./commun/depil_b.c\
					./commun/ft_petit_nbr6.c\
					./commun/gestion_erreur.c\
					./commun/rarbrr.c\
					./commun/stock_print.c\
					./commun/ft_depil_sens.c\
					./commun/ft_push_b_1.c\
					./commun/papb.c\
					./commun/rrarrbrrr.c\
					./commun/tri_mediane.c\
					./commun/ft_petit_nbr.c\
					./commun/ft_rot_sens.c\
					./commun/placement.c\
					./commun/sasbss.c\
					./pushswap/main_pushswap.c\

SRCS_C = 			./pushswap/algo.c\
					./pushswap/algo1.c\
					./pushswap/option.c\
					./commun/depil_b.c\
					./commun/ft_petit_nbr6.c\
					./commun/gestion_erreur.c\
					./commun/rarbrr.c\
					./commun/stock_print.c\
					./commun/ft_depil_sens.c\
					./commun/ft_push_b_1.c\
					./commun/papb.c\
					./commun/rrarrbrrr.c\
					./commun/tri_mediane.c\
					./commun/ft_petit_nbr.c\
					./commun/ft_rot_sens.c\
					./commun/placement.c\
					./commun/sasbss.c\
					./checker_push/main_checker.c\

RM = rm -f

OBJS = $(SRCS:.c=.o)

OBJS_P = $(SRCS_P:.c=.o)

OBJS_C = $(SRCS_C:.c=.o)

CURRENT_DIR = $(shell pwd)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	@make -C ./commun/libft
	@echo 'COMPILATION LIBFT'

$(NAME): $(OBJS)
	@echo 'COMPILATION LIBFT'
	@make -C ./commun/libft
	@echo "COPIE LIBFT.A DANS DOSSIER COURANT"
	@cp ./commun/libft/libft.a ./libft.a
	@echo 'CREATION PUSH_SWAP'
	@$(CC) $(FLAGS) $(OBJS_P) libft.a -o $(NAME)
	@echo 'CREATION CHECKER'
	@$(CC) $(FLAGS) $(OBJS_C) libft.a -o $(NAME_C)

clean:
	@echo 'SUPPRESSION .o'
	$(RM) $(OBJS)
	@cd ./commun/libft/ && make clean

fclean: clean
	@echo 'SUPPRESSION PUSH_SWAP'
	@$(RM) $(NAME)
	@echo 'SUPPRESSION CHECKER'
	@$(RM) $(NAME_C)
	@echo 'SUPPRESSION LIBFT.a'
	@$(RM) libft.a 
	@cd ./commun/libft/ && make fclean

re: fclean all

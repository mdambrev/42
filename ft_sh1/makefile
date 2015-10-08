#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 13:20:45 by mdambrev          #+#    #+#              #
#    Updated: 2015/10/08 15:50:51 by mdambrev         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS 	= -Wall -Wextra -Werror -g -Ofast

NAME 	= ft_sh1

LIB 	= libft/libft.a

INC_LIB = ./libft/includes/

SRC 	= main.c \
		  parsing_get.c \
		  get_next_line.c \
		  split_line.c \
		  dup_env.c \
		  s_bin.c \
		  builds.c \
		  setenv.c \
		  fork_bin.c \
		  cd.c \

OBJ 	= $(SRC:.c=.o)
SRCDIR 	= ./srcs/
INCDIR  = ./includes/
SRCS    = $(addprefix $(SRCDIR), $(SRC))


all:$(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -c $(SRCS) -I $(INC_LIB) -I $(INCDIR)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L./libft -lft


relib:
	cd libft; make clean; make fclean; make;

clean: 
	@Make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@Make -C libft/ fclean
	@rm -rf $(NAME)
norm:
	norminette $(SRCDIR)

re: fclean all

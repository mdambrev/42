#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 13:20:45 by mdambrev          #+#    #+#              #
#    Updated: 2015/05/28 17:57:28 by mdambrev         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS 	= -Wall -Wextra -Werror

NAME 	= push_swap

LIB 	= mylib/libft.a

INC_LIB = ./mylib/includes/

SRC 	= main.c \
		  error.c \
		  list.c \
		  operation.c \
		  operation2.c \
		  sort.c \

OBJ 	= $(SRC:.c=.o)
SRCDIR 	= ./srcs/
INCDIR  = ./includes/
SRCS    = $(addprefix $(SRCDIR), $(SRC))


all:$(NAME)

$(NAME):
	@make -C mylib/
	@gcc $(FLAGS) -c $(SRCS) -I $(INC_LIB) -I $(INCDIR)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L./mylib -lft


relib:
	cd mylib; make clean; make fclean; make;

clean: 
	@Make -C mylib/ clean
	@rm -rf $(OBJ)

fclean: clean
	@Make -C mylib/ fclean
	@rm -rf $(NAME)
norm:
	norminette $(SRCDIR)

re: fclean all

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 13:20:45 by mdambrev          #+#    #+#              #
#    Updated: 2015/08/17 16:54:50 by mdambrev         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS 	= -Wall -Wextra -Werror -g

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit  

NAME 	= FdF

LIB 	= mylib/libft.a

INC_LIB = ./mylib/includes/ \

SRC 	= main.c \
		  draw.c \
		  parsing.c \
		  get_next_line.c \

OBJ 	= $(SRC:.c=.o)
SRCDIR 	= ./srcs/
INCDIR  = ./includes/
SRCS    = $(addprefix $(SRCDIR), $(SRC))

all:$(NAME)

$(NAME):
	@make -C mylib/
	@make -C mlx/
	@gcc $(FLAGS) -c $(SRCS) -I $(INC_LIB) -I $(INCDIR)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) ./mlx/libmlx.a  -L./mylib -lft  

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

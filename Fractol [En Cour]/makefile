#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 13:20:45 by mdambrev          #+#    #+#              #
#    Updated: 2015/09/08 11:05:31 by mdambrev         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS 	= -Wall -Wextra -Werror -g -Ofast

NAME 	= Fractol

LIB 	= libft/libft.a

MLXFLAGS= -lmlx -framework OpenGL -framework Appkit

INC_LIB = ./libft/includes/

SRC 	= main.c \
		  draw.c \
		  julia.c \
		  mandelbrot.c \
		  parsing.c \
		  direction.c \
		  put_image.c \
		  chromosome.c \

OBJ 	= $(SRC:.c=.o)
SRCDIR 	= ./srcs/
INCDIR  = ./includes/
SRCS    = $(addprefix $(SRCDIR), $(SRC))


all:$(NAME)

$(NAME):
	@make -C libft/
	@make -C mlx/
	@gcc $(FLAGS) -c $(SRCS) -I $(INC_LIB) -I $(INCDIR)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) ./mlx/libmlx.a -L./libft -lft


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

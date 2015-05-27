#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 13:20:45 by mdambrev          #+#    #+#              #
#    Updated: 2015/04/18 18:59:07 by mdambrev         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS 	= -Wall -Wextra -Werror

NAME 	= ft_ls

LIB 	= libft/libft.a

INC_LIB = ./libft/includes/

INC		= ft_ls.h

SRC 	= ft_ls.c\
	  	ft_ls_forms.c\
		ft_ls_option.c\
		ft_ls_args.c\
		ft_ls_main.c\
		ft_ls_form_r.c\
		ft_ls_add.c\
		ft_ls_add2.c\
		ft_ls_add3.c\
		ft_ls_add4.c\
		ft_ls_folder.c\
		ft_ls_error.c\
		ft_ls_forms_l.c\
		ft_ls_parse_l.c\
		ft_ls_exclude.c\

OBJ 	= $(SRC:.c=.o)
SRCDIR 	= ./srcs/
INCDIR 	= ./includes/
SRCS    = $(addprefix $(SRCDIR), $(SRC))


all:$(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -c $(SRCS) -I $(INCDIR) -I $(INC_LIB)
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
	norminette ft_ls.h $(SRC)

re: fclean all

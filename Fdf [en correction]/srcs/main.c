/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 14:23:30 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/04 08:58:17 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	char *line;

	line = NULL;
	(void)argc;
	(void)argv;
	get_next_line(STDIN_FILENO, &line);
	printf("entrer standar == %s", line);
	/*
	int			nb_list;
	t_content	*axx;

	nb_list = ft_nb_list(argc, argv);
	axx = parsing(argc, argv, nb_list);
	main_pos(axx, nb_list);
	projection_parallele(axx, nb_list);
	draw(axx, nb_list);
	LIST_R(0);
	return (0);*/
}

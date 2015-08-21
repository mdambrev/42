/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 14:23:30 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/21 15:58:48 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	int			nb_list;
	t_content	*axx;
	int			x;

	nb_list = ft_nb_list(argc, argv);
	axx = parsing(argc, argv, nb_list);
	main_pos(axx, nb_list);
	projection_parallele(axx, nb_list);
	draw(axx, nb_list);
	LIST_R(0);
	return (0);
}

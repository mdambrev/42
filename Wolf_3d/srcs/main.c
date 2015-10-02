/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 17:50:53 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/02 02:09:48 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

int					main(int argc, char **argv)
{
	int				nb_list;
	int				x;
	t_content		*axx;

	x = 0;
	nb_list = ft_nb_list(argc, argv);
	if (nb_list == 0)
		exit(-1);
	axx = parsing(argc, argv, nb_list);
	main_pos(axx, nb_list);
	draw(argc, argv, axx, nb_list);
	return (0);
}

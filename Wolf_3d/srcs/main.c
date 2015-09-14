/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 17:50:53 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/14 13:52:37 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"




int			main(int argc, char **argv)
{
	int nb_list;
	int x;
	t_content *axx;

	x = 0;
	nb_list = ft_nb_list(argc , argv);
	if(nb_list == 0)
		exit(-1);
	axx = parsing(argc, argv, nb_list);
	main_pos(axx, nb_list);
/*	while(x < nb_list)
	{
		while(LIST_IB(x, 0) == 0)
		{
			printf("%d ", VALUE_I(x, 0));
		}
		printf("\n");
		x++;
	}*/
	draw(argc, argv, axx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 17:39:14 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/14 13:17:19 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

/*void		add_position_h(t_content *axx, int h, int nb_list, int bordure)
{
	int		x;
	int		content;

	x = 0;
	content = bordure;
	while (x < nb_list)
	{
		LIST_R(x);
		while (LIST_IB(x, 0) == 0)
		{
			{
				VALUE_I(x, 2) = content;
			}
		}
		content = content + h;
		LIST_R(x);
		x++;
	}
}*/

void		add_position_l(t_content *axx, int nb_list)
{
	int		x;
	int		y;

	y = 0;
	while (y < nb_list)
	{
		LIST_R(y);
		x = 0;
		while (LIST_IB(y, 0) == 0)
		{
			VALUE_I(y, 1) = x;
			VALUE_I(y, 2) = y;
			x++;
		}
		LIST_R(y);
		y++;
	}
}

int			main_pos(t_content *axx, int nb_list)
{
	if (VALUE_I(0, 0) == 0)
		exit(-1);
//	add_position_h(axx,u largeur, nb_list, bordure);
	add_position_l(axx, nb_list);
	return (0);
}

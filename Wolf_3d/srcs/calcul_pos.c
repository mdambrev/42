/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 17:39:14 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/24 18:51:29 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

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

int 	nb_malloc(t_content *axx,int nb_list)
{
	int		x;
	int		y;
	int 	z;

	y = 0;
	z = 0;
	while (y < nb_list)
	{
		LIST_R(y);
		x = 0;
		while (LIST_IB(y, 0) == 0)
		{
			x++;
		}
		if(x > z)
			z = x;
		y++;
	}
	return(z);
}

void transform_map(t_content *axx,int nb_list, t_clist *param)
{
	int **tab;
	int x;
	int y;
	int len_min;

	y = 0;
	len_min = 2147483647;
	tab = (int **)malloc(sizeof(int *) * nb_list + 1);
	x = nb_malloc(axx, nb_list);
	while(y < nb_list)
		tab[y++] = (int*)malloc(sizeof(int) * x);
	tab[y] = 0;
	y = 0;
	while(y < nb_list)
	{
		x = 0;
		LIST_R(y);
		while(LIST_IB(y, 0) == 0)
		{
			tab[y][x] = VALUE_I(y ,0);
			x++;
		}
		if(len_min > x)
			len_min = x;
		LIST_R(y);
		y++;
	}
	CONTENT(5) = len_min;
	CONTENT(6) = nb_list;
	PARAM(6) = tab;
}


int			main_pos(t_content *axx, int nb_list)
{
	if (VALUE_I(0, 0) == 0)
		exit(-1);
//	add_position_h(axx,u largeur, nb_list, bordure);
	add_position_l(axx, nb_list);
	return (0);
}

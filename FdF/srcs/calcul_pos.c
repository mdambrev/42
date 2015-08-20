/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 17:39:14 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/20 19:27:11 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void add_position_h(t_content *axx, int h, int nb_list, int bordure)
{
	int x;
	int content;

	x = 0;
	content = bordure;
	while(x < nb_list)
	{
		LIST_R(x);
		while(LIST_IB(x, 0) == 0)
		{
			{
				VALUE_I(x, 2) = content;
			}
		}
		content = content + h;
		LIST_R(x);
		x++;
	}
	
	x = 0;
/*	while(x < nb_list)
	{
		LIST_R(x);
		content = bordure;
		while(LIST_IB(x, 0) == 0)
		{
			{
				printf(" %d", VALUE_I(x, 2));
			}
			content = content + h;
		}
		LIST_R(x);
		printf("\n");
		x++;
	}

	(void)h;
	(void)nb_list;
*/
}

void add_position_l(t_content *axx, int  l, int nb_list, int bordure)
{
	int x;
	int content;

	x = 0;
	content = bordure;
	while(x < nb_list)
	{
		content = bordure;
		LIST_R(x);
		while(LIST_IB(x, 0) == 0)
		{
			{
				VALUE_I(x, 1) = content;
			}
			content = content + l;
		}
		LIST_R(x);
		x++;
	}
	
	x = 0;
/*	while(x < nb_list)
	{
		LIST_R(x);
		content = bordure;
		while(LIST_IB(x, 0) == 0)
		{
			{
				printf(" %d", VALUE_I(x, 1));
			}
		}
		LIST_R(x);
		printf("\n");
		x++;
	}
*/	
}

int main_pos(t_content *axx, int nb_list)
{
	int hauteur;
	int largeur;
	int bordure;
	
	bordure = 50;
	hauteur = (LARGEUR - bordure) / nb_list;
	largeur = (HAUTEUR - bordure) / VALUE_I(0, 0);
	bordure = 50;
	add_position_h(axx, hauteur, nb_list, bordure);
	add_position_l(axx, largeur, nb_list, bordure);
	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 16:33:56 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/02 01:42:19 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void			del_tab(char ***tab1)
{
	char		**tab;
	int			x;

	x = 0;
	tab = *tab1;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab[x]);
	free(tab);
}

void			write_buffeur(t_clist *param, int x)
{
	int			y;
	t_env		*e;
	int			color;

	e = PARAM(5);
	if (e->side == 0 && e->pos_x > e->map_x)
		color = 0xFFFF00;
	else if (e->side == 1)
		color = 0x00FF00;
	else if (e->side == 2)
		color = 0xFF0000;
	else if (e->side == 0 && e->pos_x < e->map_x)
		color = 0x0000FF;
	y = e->draw_start;
	while (y < e->draw_end)
	{
		pixel_put(param, y, x, color);
		y++;
	}
}

void			set_hauteur(t_clist *param)
{
	t_env		*e;

	e = PARAM(5);
	e->line_height = abs((int)(HAUTEUR / e->perpwalldist));
	e->draw_start = (-1 * ((e->line_height)) / 2) + (HAUTEUR / 2);
	if (e->draw_start < 0)
		e->draw_start = 0;
	e->draw_end = (e->line_height / 2) + (HAUTEUR / 2);
	if (e->draw_end >= HAUTEUR)
		e->draw_end = HAUTEUR - 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 14:08:40 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/21 15:43:52 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

static void		norm(t_content *axx, t_clist *param)
{
	int			x;
	int			y;

	x = 0;
	y = 1;
	while (y < CONTENT(0))
	{
		LIST_R(x);
		LIST_R(y);
		while (LIST_IB(y, 0) == 0 && LIST_V(x, 0) != LIST_V(x, 2))
		{
			LIST_I(x, 0);
			tracer_bresenham(param, LIST_A(x), LIST_A(y));
		}
		LIST_R(x);
		LIST_R(y);
		y++;
		x++;
	}
}

void			trace_map(t_content *axx, t_clist *param)
{
	int			x;
	int			y;

	x = 0;
	y = 1;
	LIST_R(0);
	while (x < CONTENT(0))
	{
		while (LIST_IB(x, 0) == 0 && LIST_V(x, 0) != LIST_V(x, 2))
		{
			tracer_bresenham(param, LIST_A(x), LIST_V(x, 0));
		}
		LIST_R(x);
		x++;
	}
	norm(axx, param);
}

int				set_color(t_clist *a, t_clist *b)
{
	int			bob;

	bob = 0;
	if (((t_int*)((t_clist *)b + 3)->bit)->t_x != 0
			|| ((t_int*)((t_clist *)a + 3)->bit)->t_x != 0)
		bob = 0xFF0000;
	else
		bob = 0x00FF00;
	return (bob);
}

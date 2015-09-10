/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:27:23 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/08 10:40:29 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			norm(t_clist *param, t_env *e)
{
	while (e->x < e->image_x && e->x < LARGEUR)
	{
		e->y = 0;
		while (e->y < e->image_y && e->y < HAUTEUR)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			e->d = 1;
			while (e->d < 4 && e->i < e->iteration_max)
			{
				e->tmp = e->z_r;
				e->z_r = (e->z_r * e->z_r) - (e->z_i * e->z_i) + e->c_r;
				e->z_i = (2 * e->z_i * e->tmp) + e->c_i;
				e->d = (e->z_r * e->z_r + e->z_i * e->z_i);
				e->i++;
			}
			if (e->i != e->iteration_max)
				pixel_put(param, e->y, e->x, (0x0000FF) + e->i * 15);
			e->y++;
		}
		e->x++;
	}
}

void				main_mandelbrot(t_clist *param)
{
	t_env			e;

	e.d = 0;
	e.x = 0;
	e.y = 0;
	e.zoom = CONTENT(5);
	e.x1 = -1.8 * CONTENT(4);
	e.x2 = 1.8 * CONTENT(3);
	e.y1 = -1.2 * CONTENT(1);
	e.y2 = 1.2 * CONTENT(2);
	e.image_x = (e.x2 - e.x1) * e.zoom;
	e.image_y = (e.y2 - e.y1) * e.zoom;
	e.iteration_max = CONTENT(6);
	e.zoom_x = e.image_x / (e.x2 - e.x1);
	e.zoom_y = e.image_y / (e.y2 - e.y1);
	e.i = 0;
	norm(param, &e);
}

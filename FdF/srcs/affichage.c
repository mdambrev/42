/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 19:02:15 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/21 15:39:24 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void				stock_param(t_clist *param, t_clist *a, t_clist *b)
{
	CONTENT(2) = ((t_int*)((t_clist *)a + 3)->bit + 1)->t_x;
	CONTENT(3) = ((t_int*)((t_clist *)a + 3)->bit + 2)->t_x;
	CONTENT(4) = ((t_int*)((t_clist *)b + 3)->bit + 1)->t_x;
	CONTENT(5) = ((t_int*)((t_clist *)b + 3)->bit + 2)->t_x;
}

static void			norm1(t_clist *param, int *dx, int *dy)
{
	*dx = CONTENT(4) - CONTENT(2);
	*dy = CONTENT(5) - CONTENT(3);
	if (*dx > 0)
		CONTENT(6) = 1;
	else
		CONTENT(6) = -1;
	if (*dy > 0)
		CONTENT(7) = 1;
	else
		CONTENT(7) = -1;
	if (*dx < 0)
		*dx = *dx * (-1);
	if (*dy < 0)
		*dy = *dy * (-1);
	CONTENT(8) = 0;
}

static void			norm2(t_clist *param, int dx, int dy)
{
	int				cumul;

	cumul = 0;
	while (CONTENT(8) < dx)
	{
		CONTENT(2) += CONTENT(6);
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			CONTENT(3) += CONTENT(7);
		}
		mlx_pixel_put(PARAM(0), PARAM(1),
		CONTENT(2), CONTENT(3), (int)CONTENT(9));
		CONTENT(8) += 1;
	}
}

static void			norm3(t_clist *param, int dx, int dy)
{
	int				cumul;

	cumul = dy / 2;
	while (CONTENT(8) < dy)
	{
		CONTENT(3) += CONTENT(7);
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			CONTENT(2) += CONTENT(6);
		}
		mlx_pixel_put(PARAM(0), PARAM(1),
		CONTENT(2), CONTENT(3), (int)CONTENT(9));
		CONTENT(8) += 1;
	}
}

void				tracer_bresenham(t_clist *param, t_clist *a, t_clist *b)
{
	int				dx;
	int				dy;

	stock_param(param, a, b);
	CONTENT(9) = set_color(a, b);
	norm1(param, &dx, &dy);
	if (dx > dy)
		norm2(param, dx, dy);
	else
		norm3(param, dx, dy);
}

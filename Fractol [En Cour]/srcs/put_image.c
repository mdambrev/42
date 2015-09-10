/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 00:28:06 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/08 10:44:47 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_image(t_clist *param)
{
	int			bpp;
	int			size_line;
	int			endian;

	PARAM(2) = mlx_new_image(PARAM(0), LARGEUR, HAUTEUR);
	PARAM(3) = mlx_get_data_addr(PARAM(2), &bpp, &size_line, &endian);
	CONTENT(10) = (double)bpp;
	CONTENT(11) = (double)size_line;
	CONTENT(12) = (double)endian;
}

void			pixel_put(t_clist *param, int x, int y, int col)
{
	int			pos;

	pos = (y * CONTENT(10) / 8) + (x * (CONTENT(10) / 8) * LARGEUR);
	if ((y > 0 && y < LARGEUR) && x > 0 && x < HAUTEUR)
		ft_memcpy(PARAM(3) + pos, &col, 4);
}

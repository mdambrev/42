/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 16:33:56 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/08 10:05:45 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					direction(t_clist *param, int keycode)
{
	static long double	up = 1;
	static long double	down = 1;
	static long double	left = 1;
	static long double	right = 1;
	long double			x;

	x = CONTENT(5) / 150;
	if (keycode == 124)
	{
		left += 0.2 / x;
		right -= 0.2 / x;
	}
	if (keycode == 123)
		right += 0.2 / x;
	if (keycode == 125)
	{
		up -= 0.2 / x;
		down += 0.2 / x;
	}
	if (keycode == 126)
		up += 0.2 / x;
	CONTENT(1) = up;
	CONTENT(2) = down;
	CONTENT(3) = left;
	CONTENT(4) = right;
}

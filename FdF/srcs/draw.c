/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:54:16 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/17 16:33:33 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_clist *init_param(void)
{
	t_clist *param;
	t_int *content;
	
	param = (t_clist *)malloc(sizeof(t_clist) * NB_PARAM);
	content = (t_int *)malloc(sizeof(t_int) * NB_INT);
	param->bit = content;
	return(param);
}

void test_triangle(t_clist *param)
{
	int x;
	int y;

	x = 100;
	y = 0;
	while(y < 200)
	{
		x = 0;
		while(x < 200)
		{
			mlx_pixel_put(PARAM(0), PARAM(1), x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

int expose_hook(void *param)
{
	(void)param;
	test_triangle(param);
	return(0);
}

int key_hook(int keycode ,void *param)
{
	(void)param;
	if(keycode == 53)
		exit(0);
	return(0);
}

void draw(void)
{
	t_clist *param;

	param = init_param();
	PARAM(0) = mlx_init();
	PARAM(1) = mlx_new_window(PARAM(0) , 400, 400, "bob");
	test_triangle(param);
	mlx_key_hook(PARAM(1), key_hook, param);
	mlx_expose_hook(PARAM(1), expose_hook, param);
	mlx_loop(PARAM(0));
}

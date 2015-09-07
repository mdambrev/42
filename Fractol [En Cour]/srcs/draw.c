/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:54:16 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/06 14:58:14 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_clist		*init_param(void)
{
	t_clist	*param;
	t_float	*content;
	param = (t_clist *)malloc(sizeof(t_clist) * NB_PARAM + 10);
	content = (t_float *)malloc(sizeof(t_float) * NB_INT + 10100);
	param->bit = content;
	free(PARAM(2));
	PARAM(2) = NULL;
	return (param);
}

int			expose_hook(t_clist *param)
{
	if(PARAM(2))
	{
		mlx_destroy_image(PARAM(0), PARAM(2));
	}
	if(CONTENT(0) == 1)
	{
		init_image(param);
		main_mandelbrot(param);
		mlx_put_image_to_window(PARAM(0), PARAM(1), PARAM(2), 0, 0);
	}
	else if(CONTENT(0) == 2)
	{
		init_image(param);
		main_julia(param);
		mlx_put_image_to_window(PARAM(0), PARAM(1), PARAM(2), 0, 0);
	}
	else if(CONTENT(0) == 3)
	{
		init_image(param);
		main_chromosome(param);
		mlx_put_image_to_window(PARAM(0), PARAM(1), PARAM(2), 0, 0);
	}
	return(0);
}

int			mouse_hook(int button, int x, int y, t_clist *param)
{
	if(button == 1)
	{
		CONTENT(5) *= 1.3;
		if(CONTENT(0) != 2)
			CONTENT(6) += 40;
		else 
			CONTENT(6) += 40;
		expose_hook(param);
	}
	else if((button == 2  || button == 3) && CONTENT(5) > 0)
	{
		CONTENT(5) /= 1.3;
		CONTENT(6) -= 5;
		expose_hook(param);
	}
	if(CONTENT(5) == 0)
		CONTENT(5) = 1;
	(void)param;
	(void)x;
	(void)y;
	
	return(0);	
}

int			key_hook(int keycode, t_clist *param)
{
	if(keycode == 36)
	{
		if(CONTENT(14) == 1)
			CONTENT(14) = -1;
		else if(CONTENT(14) == -1)
			CONTENT(14) = 1;
	}
	else if(keycode == 76)
	{
		if(CONTENT(15) == 1)
			CONTENT(15) = -1;
		else if(CONTENT(15) == -1)
			CONTENT(15) = 1;
	}
	else if (keycode == 53)
		exit(0);
	direction(param, keycode);
	if((keycode <= 126 && keycode >= 123) || keycode == 69 || keycode == 76)
		expose_hook(param);
	return (0);
}

int Motion_mouse_hook(int x, int y, t_clist *param)
{
	static long double t_x = 0;
	static long double t_y = 0;

	if(CONTENT(14) == -1) 
		return(0);
	t_x = LARGEUR / 2;
	t_y = HAUTEUR / 2;
	CONTENT(7) = 1 * (x / t_x) - 1;
	CONTENT(8) = 1 * (y / t_y) - 1;
	expose_hook(param);
	return(0);

}

void		draw(int argc, char **argv)
{
	t_clist	*param;

	param = init_param();
	printf("bobb\n");
	write_param(argc, argv, param);
	printf("bobb\n");
	CONTENT(1) = 1;
	CONTENT(2) = 1;
	CONTENT(3) = 1;
	CONTENT(4) = 1;
	CONTENT(6) = 150;
	CONTENT(7) = 0;
	CONTENT(8) = 0;
	CONTENT(14) = 1;
	CONTENT(15) = 1;
	CONTENT(5) = 100;
	printf("bobb\n");
	PARAM(0) = mlx_init();
	PARAM(1) = mlx_new_window(PARAM(0), LARGEUR, HAUTEUR, "fdf");
	printf("bobb2\n");
	mlx_hook(PARAM(1), 6, PointerMotionMask, Motion_mouse_hook, param);
	mlx_key_hook(PARAM(1), key_hook, param);
	mlx_mouse_hook(PARAM(1), mouse_hook, param);
	mlx_expose_hook(PARAM(1), expose_hook, param);
	mlx_loop(PARAM(0));
}

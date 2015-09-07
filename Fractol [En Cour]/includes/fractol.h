/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 15:48:52 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/07 15:30:02 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FDF_H

# define NB_INT 10
# define NB_PARAM 3 + 1
# define LARGEUR 960
# define HAUTEUR 540
# define CONTENT(x) ((t_float *)param->bit + x)->t_x
# define PARAM(x)	((t_clist *)param + 1 + x)->bit
# define PointerMotionMask	(1L<<6)
# include "libft.h"
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>

typedef struct 		s_env
{
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		zoom;
	long double		image_x;
	long double		image_y;
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		i;
	long double		x;
	long double		y;
	long double		tmp;
	long double		d;
	long double		iteration_max;
	long double		zoom_x;
	long double		zoom_y;
}					t_env;

int parsing(int argc,char **argv);
void draw(int argc, char **argv);
void main_mandelbrot(t_clist *param);
void main_julia(t_clist *param);
void write_param(int argc,char **argv,t_clist *param);
void direction(t_clist *param, int keycode);
void init_image(t_clist *param);
void pixel_put(t_clist *param, int x, int y, int col);
void main_chromosome(t_clist *param);

#endif

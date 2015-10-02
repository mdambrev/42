/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:54:16 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/02 02:05:00 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

int							expose_hook(t_clist *param)
{
	if (PARAM(2))
		mlx_destroy_image(PARAM(0), PARAM(2));
	init_image(param);
	set_to_buffeur(param, PARAM(4));
	mlx_put_image_to_window(PARAM(0), PARAM(1), PARAM(2), 0, 0);
	return (0);
}

int							key_press(int keycode, t_clist *param)
{
	if (keycode == 53)
	{
		mlx_destroy_image(PARAM(0), PARAM(2));
		exit(-1);
	}
	boolean_mouv(param, keycode);
	expose_hook(param);
	return (0);
}

int							key_release(int keycode, t_clist *param)
{
	boolean_stop_mouv(param, keycode);
	expose_hook(param);
	return (0);
}

void						draw(int argc, char **argv,
									t_content *axx, int nb_list)
{
	t_clist					*param;
	t_env					e;

	param = init_param();
	PARAM(0) = mlx_init();
	(void)argc;
	(void)argv;
	PARAM(1) = mlx_new_window(PARAM(0), LARGEUR, HAUTEUR, "Wolf_3D");
	PARAM(4) = axx;
	e = init_map();
	PARAM(5) = &e;
	transform_map(axx, nb_list, param);
	mlx_expose_hook(PARAM(1), expose_hook, param);
	mlx_loop_hook(PARAM(0), &expose_hook, param);
	mlx_hook(PARAM(1), 2, 1L << 0, &key_press, param);
	mlx_hook(PARAM(1), 3, 1L << 1, &key_release, param);
	expose_hook(param);
	mlx_loop(PARAM(0));
}

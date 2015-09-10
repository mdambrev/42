/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:54:16 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/10 14:09:33 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

int							expose_hook(t_clist *param)
{
	if (PARAM(2))
		mlx_destroy_image(PARAM(0), PARAM(2));
	init_image(param);
		// FONCTION_DE_REMPLISSAGE_DU_BUFFER ;
	mlx_put_image_to_window(PARAM(0), PARAM(1), PARAM(2), 0, 0);
	return (0);
}

int							mouse_hook(int button, int x, int y, t_clist *param)
{
		(void)x;
		(void)y;
		(void)button;
		(void)param;
		expose_hook(param);
		return (0);
}

int							key_hook(int keycode, t_clist *param)
{
	(void)keycode;
	(void)param;
	if(keycode == 53)
	{
		mlx_destroy_image(PARAM(0), PARAM(2));
		exit(-1);
	}
	printf("key_hook == %d\n", keycode);
	//expose_hook(param);
	return (0);
}

int							motion_mouse_hook(int x, int y, t_clist *param)
{
	(void)x;
	(void)y;
	(void)param;
	//expose_hook(param);
	return (0);
}

void						draw(int argc, char **argv)
{
	t_clist					*param;

	param = init_param();
	PARAM(0) = mlx_init();
	PARAM(1) = mlx_new_window(PARAM(0), LARGEUR, HAUTEUR, "Wolf_3D");
	mlx_hook(PARAM(1), 6, (1L << 6), motion_mouse_hook, param);
	mlx_key_hook(PARAM(1), key_hook, param);
	mlx_mouse_hook(PARAM(1), mouse_hook, param);
	mlx_expose_hook(PARAM(1), expose_hook, param);
	mlx_loop(PARAM(0));

	(void)argc;
	(void)argv;
}

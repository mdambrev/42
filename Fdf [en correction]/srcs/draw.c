/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:54:16 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/22 13:51:32 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_clist		*init_param(void)
{
	t_clist	*param;
	t_int	*content;

	param = (t_clist *)malloc(sizeof(t_clist) * NB_PARAM);
	content = (t_int *)malloc(sizeof(t_int) * NB_INT);
	param->bit = content;
	return (param);
}

int			expose_hook(void *param)
{
	(void)param;
	trace_map(PARAM(2), param);
	return (0);
}

int			key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

void		draw(t_content *axx, int nb_list)
{
	t_clist	*param;

	param = init_param();
	CONTENT(0) = nb_list;
	PARAM(0) = mlx_init();
	PARAM(1) = mlx_new_window(PARAM(0), LARGEUR, HAUTEUR, "fdf");
	PARAM(2) = axx;
	mlx_key_hook(PARAM(1), key_hook, param);
	mlx_expose_hook(PARAM(1), expose_hook, param);
	mlx_loop(PARAM(0));
}

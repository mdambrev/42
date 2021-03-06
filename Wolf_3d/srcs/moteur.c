/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moteur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 14:24:36 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/02 02:11:12 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

#include <sys/times.h>

void			set_to_buffeur(t_clist *param, t_content *axx)
{
	t_env		*e;
	int			x;

	x = 0;
	init_calcul(param, x);
	e = PARAM(5);
	while (x < LARGEUR)
	{
		init_calcul(param, x);
		set_vector_value(param);
		search_block(param, axx);
		correction_optique(param);
		set_hauteur(param);
		set_rotate(param);
		set_direction(axx, param);
		write_buffeur(param, x);
		x++;
	}
}

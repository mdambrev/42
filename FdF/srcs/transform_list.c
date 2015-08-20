/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 16:31:45 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/20 20:25:18 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void transform_value(t_content *axx, int x)
{
	float constante;

	constante = 2;;
	if(VALUE_I(x, 0) != 0)
	{
		VALUE_I(x, 1) += ((constante * VALUE_I(x, 0)) * -1);
		VALUE_I(x, 2) += (((constante / 2) * VALUE_I(x, 0)) * - 1);
	}
	return ;
}

void projection_parallele(t_content *axx, int nb_list)
{
	int x;

	x = 0;
	while(x < nb_list)
	{
		LIST_R(x);
		while(LIST_IB(x, 0) == 0)
		{
			transform_value(axx, x);	
		}
		x++;
	}
}

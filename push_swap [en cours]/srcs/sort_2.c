/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 03:09:23 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/12 16:01:08 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int 		inc_z(t_content *axx, int z, t_clist *nb_max, int sens)
{

	int x;

	x = pos_nb_max(axx, nb_max, sens);
	printf("z == %d, x == %d\n", z, x);
	if(sens == 1)
	{
		z = z - x;
		if(z == (VALUE_I(1, 0) - 1))
			z++;
	}
	else if (sens == 0)
	{
		;
	}
	printf("z == %d\n", z);
	return(z);
}

int set_sens(t_content *axx, t_clist *nb_max)
{
	int y;

	y = 0;
	TMP_A(8) = nb_max;
	if(TMP_V(8, 0) != TMP_V(8, 2) && TMP_V(8, 1) != TMP_V(8, 2))
	{
		if(TMP_IN(8, 1) > TMP_IN(8, 0))
			y = 1;
	}
	if(TMP_V(8, 0) == TMP_V(8, 2))
	{
		if(TMP_IN(8, 1) > VALUE_IN(1, 0))
			y = 1;
	
	}
	if(TMP_V(8, 1) == TMP_V(8, 2))
	{
		if(TMP_IN(8, 0) < VALUE_IN(1, 1))
			y = 1;
	}
	return(y);
}

int 			interrupt_loop(t_content *axx, int y, int nb)
{
	if(TMP_V(7, y) == TMP_V(0 ,2))
	{
		printf("COND 1  ||| %d > %d > %d\n", TMP_I(7, 0) ,nb, VALUE_IN(1, y));
		if(TMP_I(7, 0) > nb && nb  > VALUE_IN(1, y))	
			return(1);
	}
	else if(TMP_V(7, y) != TMP_V(0 ,2))
	{
		printf("COND 2  ||| %d > %d > %d\n", TMP_I(7, 0) ,nb, TMP_IN(7, y));
		if(TMP_I(7, 0) > nb && nb  > TMP_IN(7, y))	
			return(1);
	}
	return(0);
}

void	 		inc_list(t_content *axx, int y)
{
	LIST_I(NB_LIST + 7, y);
	if(TMP_A(7) == TMP_V(7, 2))
		LIST_I(NB_LIST + 7, y);
}
	int			pos_nb_max(t_content *axx, t_clist *nb_max, int y)
{
	int x;

	x = 0;
	TMP_A(8) = nb_max;
	while(TMP_A(8) != TMP_V(8, 2))
	{
		x++;
		LIST_I(NB_LIST + 8, y);
	}
	return(x);
}

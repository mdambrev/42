/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 03:09:23 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/08 11:34:19 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int 		inc_z(t_content *axx, int nb, int y, t_clist *nb_max)
{
	static int tmp = 0;

	if(TMP_A(7) == nb_max)
		return(0);
	if(y == 1)
		y = 0;
	else 
		y = 1;
	tmp =  TMP_IN(7, y);
	if(tmp != 0)
	{
//		tmp = TMP_V(8, y);
		printf("nb0 == %d, nb == %d ,nb1 ==  %d \n",TMP_I(7, 0), nb, tmp );
		if(y == 1)
		{
			if(TMP_I(7, 0) > nb &&  nb > tmp)
				return(1);
		}
		if(y == 0)
		{
			if(TMP_I(7, 0) < nb && nb < tmp)
				return(1);
		}
	}
	return(0);
}

int 		inc_list_pos_x(t_content *axx, int *y, int *z, t_clist *nb_max, int nb)
{
	if(TMP_IN(7, 0) < TMP_I(7, 0) < TMP_IN(7 , 1) && (TMP_A(7) == nb_max)) 
		*y = 0;
	else if(TMP_IN(7, 0) > TMP_I(7, 0) > TMP_IN(7 , 1) && (TMP_A(7) == nb_max)) 
		*y = 1;
	if(TMP_A(7) == TMP_V(7, 2))
		LIST_I(NB_LIST + 7, *y);
	if((inc_z(axx, nb, *y, nb_max) == 1))
		return(1);
	else if(TMP_A(7) != nb_max)
		*z = *z + 1;
	if(TMP_V(7, *y) == TMP_V(7, 2) && TMP_A(7) != nb_max)
	{
		if(TMP_I(7, 0) < VALUE_IN(1, *y))
			return(1);
		if(TMP_I(7, 0) > VALUE_IN(1 ,*y))
			LIST_I(NB_LIST + 7, *y);
	}
	 if(TMP_A(7) == nb_max)
	{
		if(TMP_V(7, 0) != TMP_V(7, 2) && TMP_V(7, 1) != TMP_V(7, 2))
		{
			if(TMP_IN(7, 0) < TMP_IN(7 , 1) && (*y = 1))
				LIST_I(NB_LIST + 7, 1);
			else if(TMP_IN(7, 0) > TMP_IN(7 , 1))
				LIST_I(NB_LIST + 7, 0);
		}
		else if (TMP_V(7, 0) == TMP_V(7, 2))
		{
			if(TMP_IN(7, 0) < VALUE_IN(1 , 1) && (*y = 1))
				LIST_I(NB_LIST + 7, 1);
			else if(TMP_IN(7, 0) > VALUE_IN(1 , 1) && (*y = 0))
				LIST_I(NB_LIST + 7, 0);
		}
		else if (TMP_V(7, 1) == TMP_V(7, 2))
		{
			if(TMP_IN(7, 1) < VALUE_IN(1 , 0) && (*y = 1))
				LIST_I(NB_LIST + 7, 0);
			else if(TMP_IN(7, 1) > VALUE_IN(1 , 0) && (*y = 0))
				LIST_I(NB_LIST + 7, 1);
		}
	}
	else
	{
		if(TMP_I(7, 0) < TMP_IN(7, *y))
			return(1);
		LIST_I(NB_LIST + 7, *y);
	}
	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:20:36 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/08 11:46:47 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int cmp2(int a, int b)
{	
	return(a < b);
}

int			check_list(t_content *axx, int n_list)
{
	int x;

	x = 1;
	TMP_A(0) = LIST_A(n_list);
	LIST_R(NB_LIST);
	while(LIST_IB(NB_LIST, 0) == 0)
	{
		if(TMP_A(0)->bit != TMP_V(0, 2))
		{
			if(cmp2(TMP_I(0, 0) , TMP_IN(0, 0)) == 0)
				return(x);
		}
		x++;
	}
	return(0);
}

int pos_x(t_content *axx, int nb)
{
	static t_clist *nb_max = NULL;
	int x;
	int y;
	int z;

	y = 0;
	z = 0;
	x = VALUE_I(1, 0);
	if(LIST_V(1, 0) != LIST_V(1 , 2))
	{
		if(nb_max == NULL)
			nb_max = LIST_V(1, 1);
		if(((t_int*)((t_clist*)nb_max + 3)->bit)->t_x < VALUE_IN(1, 1))
			nb_max = LIST_V(1 , 1);
		TMP_A(7) = nb_max;	
		printf("nb_max = %d, nb = %d\n", ((t_int*)((t_clist*)nb_max +  3)->bit)->t_x, nb);
		printf("\n value = %d \n", VALUE_I(1, 0));
		while(--x && VALUE_I(1 , 0) > 2)
		{
			if(inc_list_pos_x(axx, &y, &z, nb_max, nb) == 1)
					break;
		}
	}
	return(z);
}



void inc_list(t_content *axx, int x)
{
	int y;

	y = pos_x(axx, x);
	if((y + 2) == VALUE_I(1, 0))
		y = 0;
	printf("y = %d\n", y);
	while(--y > 0)
	{
		r_b(axx);
	}
	p_b(axx);
}

void test_sort(t_content *axx)
{
	TMP_A(6) = LIST_A(0);
	TMP_A(5) = LIST_A(0);
	TMP_A(4) = LIST_A(0);
	while(((TMP_V(5, 2) != TMP_V( 5, 0)) && (TMP_A(NB_LIST + 5) != TMP_V(5, 2))))
	{
		LIST_R(NB_LIST + 6);	
		LIST_I(NB_LIST + 6, 1);	 
/*		if(TMP_IN(4, 0) > TMP_IN(4, 1))
			r_a(axx);
		else if(TMP_IN(6, 1) < TMP_I(6, 0) && TMP_V(6, 2) != TMP_V(6, 0))
		{
			printf("\n||TMP0 = %d ;  TMP1 == %d\n", TMP_IN(6,1), TMP_I(6,0) );
	//		s_a(axx); 
		}
		else */
			inc_list(axx, TMP_IN(4, 1));
	}
}

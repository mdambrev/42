/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:20:36 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/12 16:30:21 by mdambrev         ###   ########.fr       */
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

int pos_x(t_content *axx, int nb, int *sens)
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
		y = set_sens(axx, nb_max);
		TMP_A(7) = nb_max;	
		printf("nb_max = %d, nb = %d\n", ((t_int*)((t_clist*)nb_max +  3)->bit)->t_x, nb);
		printf("\n value = %d \n", VALUE_I(1, 0));
		while(--x && VALUE_I(1 , 0) > 3)
		{
			printf("\n\n sens = %d \n\n", y);
			printf("tmp7 == %d\n", TMP_I(7, 0));
				z++;
			if(interrupt_loop(axx, y, nb) == 1)
				break;
			inc_list(axx, y);
		}
		if((VALUE_I(1, 0) - 1) == z && (TMP_I(7, 0) < TMP_IN(7, y)))
			z++;
		z =  inc_z(axx, z, nb_max, y);
	}
	*sens = y;
	if(VALUE_I(1, 0) <= 3)
	   z = 0;	
	return(z);
}



void set_nb_rotate(t_content *axx, int x)
{
	int y;
	int c;
	int sens;

	c = 9;
	y = pos_x(axx, x, &sens);
	if(y < 0)
		y = -y;
	if(sens == 1)
		c = 9;
	else 
		c = 6;
	while(y-- > 0)
	{
		op(axx, c);
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
			set_nb_rotate(axx, TMP_IN(4, 1));
	}
}

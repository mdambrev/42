/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:20:36 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/04 18:59:43 by mdambrev         ###   ########.fr       */
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

int cmp3(int a, int b)
{
	return(a > b);
}
int			Rcheck_list(t_content *axx, int n_list)
{
	int x;

	x = 1;
	TMP_A(0) = LIST_A(n_list);
	LIST_R(NB_LIST);
	while(LIST_IB(NB_LIST, 0) == 0)
	{
		if(TMP_A(0)->bit != TMP_V(0, 2))
		{
			if(cmp3(TMP_I(0, 0) , TMP_IN(0, 0)) == 0)
				return(x);
		}
		x++;
	}
	return(0);
}



int pos_x(t_content *axx, int nb)
{
	int x;

	x = 0;
	TMP_A(4) = LIST_A(0);
	LIST_R(NB_LIST + 4);
	while(LIST_IB(NB_LIST + 4, 0) == 0)
	{
		x++;
		if(TMP_I(4, 0) == nb)
			break;
	}
	return(x);
}

/*void	test_sort(t_content *axx)
{
	int x;

	x = 0;
	TMP_A(3) = LIST_A(0);
	LIST_R(NB_LIST + 3);
	while(LIST_IB(2, 0) == 0)
	{
		if(check_list(axx, 0) != 0)
		{
			push_b(axx, (x = pos_x(axx, VALUE_I(2, 0))));
		}
		else 
			break;
	}
		while(VALUE_I(1, 0) > 1)
			push_a(axx , 1);
}*/


void test_sort(t_content *axx)
{

	TMP_A(3) = LIST_A(0);
	TMP_A(4) = LIST_A(0);
	TMP_A(5) = LIST_A(1);
	
	while(check_list(axx, 0) != 0 && (Rcheck_list(axx , 1) >= 0 ) )
	{
	
		LIST_I(NB_LIST + 3, 1);
		LIST_I(NB_LIST + 5, 1);
		 if(TMP_I(3, 0) < TMP_IN(3 , 1) && (TMP_IN(4, 0) < TMP_IN(4, 1)))
		{
				op(axx , 0);
		}
		else  if(TMP_IN(4, 0) > TMP_IN(4, 1))
		{
				 op(axx, 5);
		}
		else if(TMP_I(5, 0) > TMP_IN(5, 1) && VALUE_I(1, 0) > 2)
			s_b(axx );
	 	else
		{
		   	push_b(axx, 100);
			r_a(axx);
		}
		TMP_A(3) = LIST_A(0);
		LIST_R(NB_LIST + 3);
		LIST_R(NB_LIST + 4);
		LIST_R(NB_LIST + 5);
	}
//*	while(VALUE_I(1, 0) > 1)
//*		push_a(axx , 100);
}

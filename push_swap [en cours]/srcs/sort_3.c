/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 08:04:28 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/14 14:25:08 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void tri_basic(t_content *axx)
{
	TMP_A(4) = LIST_A(3);
	LIST_I(NB_LIST + 4, 0);
	while(check_list(axx, 0) != 0)
	{
		TMP_A(3) = LIST_A(0);
		LIST_I(NB_LIST + 3, 1);
		TMP_A(7) = LIST_A(0);
		LIST_I(NB_LIST + 7, 0);
		if(VALUE_IN(0, 0) < VALUE_IN(0, 1))
		{
			op(axx, 5);
		}
		else if(VALUE_IN(0, 0) < TMP_IN(7, 0))
		{
			op(axx, 8);
			op(axx, 8);
			op(axx, 0);
			op(axx, 5);
			op(axx, 5);
		}
		else if(TMP_IN(3, 1) < VALUE_IN(0, 1))
		{
			op(axx, 0);
		}
		else
		{
	   		push_b(axx, pos_x(axx, TMP_I(4, 0)));
			LIST_I(NB_LIST + 4, 0);
		}
	}
}

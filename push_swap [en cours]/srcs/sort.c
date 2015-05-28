/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:20:36 by mdambrev          #+#    #+#             */
/*   Updated: 2015/05/28 20:18:24 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int cmp2(int a, int b)
{	
	return(a < b);
}

int			check_list(t_content *axx)
{
	TMP_A(0) = LIST_A(0);
	LIST_R(NB_LIST);
	while(LIST_IB(NB_LIST, 0) == 0)
	{
		if(TMP_A(0)->bit != TMP_V(0, 2))
		{
			if((cmp2(TMP_I(0, 0) , ((t_int*)((t_clist*)LIST_V(NB_LIST, 0) + 3)->bit)->t_x)) == 0)
				return(0);
		}
	}
	return(1);
}

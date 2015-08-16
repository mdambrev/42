/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 08:04:28 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/15 18:37:53 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static	void		norm(t_content *axx)
{
	TMP_A(7) = LIST_A(0);
	LIST_I(NB_LIST + 7, 0);
	TMP_A(8) = LIST_A(0);
	LIST_R(NB_LIST + 8 );
	LIST_I(NB_LIST + 8, 0);
	LIST_I(NB_LIST + 8, 0);
	if (VALUE_IN(0, 0) < TMP_IN(7, 0)
			&& VALUE_IN(0, 0) > TMP_IN(8, 0)
				&& check_list(axx, NB_LIST + 8) == 0)
	{
		op(axx, 8);
		op(axx, 8);
		op(axx, 0);
		op(axx, 5);
		op(axx, 5);
	}
}

void				tri_basic(t_content *axx)
{
	TMP_A(4) = LIST_A(3);
	LIST_I(NB_LIST + 4, 0);
	norm(axx);
	while (check_list(axx, 0) != 0)
	{
		TMP_A(3) = LIST_A(0);
		LIST_I(NB_LIST + 3, 1);
		TMP_A(8) = LIST_A(0);
		LIST_I(NB_LIST + 8, 0);
		LIST_I(NB_LIST + 8, 0);
		if (VALUE_IN(0, 0) < VALUE_IN(0, 1))
		{
			op(axx, 5);
		}
		else if (TMP_IN(3, 1) < VALUE_IN(0, 1))
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

void				rrb(t_content *axx)
{
	if (((t_clist*)LIST_V(1, 1) + 3)->bit != 0 && VALUE_I(1, 0) > 2)
	{
		PUSH2(1, 1);
		move_chain(axx, 0, 2);
		if (VALUE_I(2, 0) == 1)
			ft_putstr("rrb ");
	}
	if (VALUE_I(2, 0) == 2)
	{
		ft_putstr("rrb :");
		verboz(axx);
	}
}

void				rrr(t_content *axx)
{
	rrb(axx);
	rra(axx);
	if (VALUE_I(2, 0) == 1)
		ft_putstr("rrr ");
	if (VALUE_I(2, 0) == 2)
	{
		ft_putstr("rrr :");
		verboz(axx);
	}
}

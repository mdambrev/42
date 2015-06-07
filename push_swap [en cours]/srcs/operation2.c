/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 17:58:21 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/07 09:55:56 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void verboz(t_content *axx)
{
	ft_putstr("\n\nPa = {  ");
	TMP_A(8) = LIST_A(0);
	LIST_R(NB_LIST + 8);
	while(LIST_IB(NB_LIST + 8, 0) == 0)
	{
		ft_putchar(' ');
		ft_putnbr(TMP_I(8, 0));
		ft_putstr("  ; ");
	}
	ft_putendl("  }");
	ft_putstr("\nPb = {  ");
	TMP_A(8) = LIST_A(1);
	LIST_R(NB_LIST + 8);
	while(LIST_IB(NB_LIST + 8, 0) == 0)
	{
		ft_putchar(' ');
		ft_putnbr(TMP_I(8, 0));
		ft_putstr("  ; ");
	}
	ft_putendl("  }\n");
	ft_putendl("--------------------------------------------------------------\n");
}



void r_a(t_content *axx)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit != 0)
	{
		PUSH2(0,0);
		move_chain(axx, 0, -1);
		if(VALUE_I(2, 0) == 1)
			ft_putstr("ra ");
		if(VALUE_I(2, 0) == 2)
		{
			ft_putstr("ra :");
			verboz(axx);
		}
	}
}

void r_b(t_content *axx)
{
	if(((t_clist*)LIST_V(1, 1) + 3)->bit != 0)
	{
		PUSH2(1,1);
		move_chain(axx, 0, -1);
		if(VALUE_I(2, 0) == 1)
			ft_putstr("rb ");
		if(VALUE_I(2, 0) == 2)
		{
			ft_putstr("rb :");
			verboz(axx);
		}

	}
}

void rr(t_content *axx)
{
	r_a(axx);
	r_b(axx);
	if(VALUE_I(2, 0) == 1)
		ft_putstr("rr ");
	if(VALUE_I(2, 0) == 2)
	{
		ft_putstr("rr :");
		verboz(axx);
	}
}

void rra(t_content *axx)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit != 0 && VALUE_I(0, 0) > 2)
	{
		PUSH2(0,0);
		move_chain(axx, 0, 2);
		if(VALUE_I(2, 0) == 1)
			ft_putstr("rra ");
		if(VALUE_I(2, 0) == 2)
		{
			ft_putstr("rra :");
			verboz(axx);
		}

	}
}

void rrb(t_content *axx)
{
	if(((t_clist*)LIST_V(1, 1) + 3)->bit != 0 && VALUE_I(1, 0) > 2)
	{
		PUSH2(1,1);
		move_chain(axx, 0, 2);
		if(VALUE_I(2, 0) == 1)

			ft_putstr("rrb ");
	}
	if(VALUE_I(2, 0) == 2)
	{
		ft_putstr("rrb :");
		verboz(axx);
	}
}

void rrr(t_content *axx)
{
	rrb(axx);
	rra(axx);	
	if(VALUE_I(2, 0) == 1)
		ft_putstr("rrr ");
	if(VALUE_I(2, 0) == 2)
	{
		ft_putstr("rrr :");
		verboz(axx);
	}
}

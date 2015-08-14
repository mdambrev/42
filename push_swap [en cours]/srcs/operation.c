/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 15:04:40 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/14 14:20:21 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void p_b(t_content *axx)
{
	if(LIST_V(0, 0) == LIST_V(0, 2))
		return;
	if(((t_clist*)LIST_V(0, 1) + 3)->bit!= 0)
	{
		PUSH2(0, 1);
		move_chain(axx, -1, 0);
		if(VALUE_I(2, 0) == 1)
			ft_putstr("pb ");
		if(VALUE_I(2, 0) == 2)
		{
			ft_putstr("pb :");
			verboz(axx);
		}
		VALUE_I(0, 0)--;
		VALUE_I(1, 0)++;
	}
}

void p_a(t_content *axx)
{
	if(LIST_V(1, 0) == LIST_V(1, 2))
		return;
	if(((t_clist*)LIST_V(1, 1) + 3)->bit != 0)
	{
		PUSH2(1, 0);
		move_chain(axx, -1, 0);
		if(VALUE_I(2, 0) == 1)
			ft_putstr("pa ");
		if(VALUE_I(2, 0) == 2)
		{
			ft_putstr("pa :");
			verboz(axx);
			VALUE_I(0, 0)++;
			VALUE_I(1, 0)--;	
		}
	}
}

void s_a(t_content *axx)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit!= 0 && VALUE_I(0 ,0) > 2)
	{
		PUSH2(0, 0);
		move_chain(axx, -1, -2);
		if(VALUE_I(2, 0) == 1)
			ft_putstr("sa ");
		if(VALUE_I(2, 0) == 2)
		{
			ft_putstr("sa :");
			verboz(axx);
		}
	}
}

void s_b(t_content *axx)
{
	if(((t_clist*)LIST_V(1, 1) + 3)->bit!= 0 && VALUE_I(1, 0) > 2)
	{
		PUSH2(1, 1);
		move_chain(axx, -1, -2);
		if(VALUE_I(2, 0) == 1)
			ft_putstr("sb ");
		if(VALUE_I(2, 0) == 2)
		{
			ft_putstr("sb :");
			verboz(axx);
		}
	}
}

void ss(t_content *axx)
{
	s_a(axx);
	s_b(axx);
	if(VALUE_I(2, 0) == 1)
		ft_putstr("ss ");
	if(VALUE_I(2, 0) == 2)
		{
			ft_putstr("ss  :" );
			verboz(axx);
		}
}

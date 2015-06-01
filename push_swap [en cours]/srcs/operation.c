/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 15:04:40 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/01 03:50:21 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void p_b(t_content *axx, int y)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit!= 0)
	{
		PUSH2(0, 1);
		move_chain(axx, -1, 0);
		if(y == 1)
			ft_putstr("pb ");
	}
}

void p_a(t_content *axx, int y)
{
	if(((t_clist*)LIST_V(1, 1) + 3)->bit!= 0)
	{
		PUSH2(1, 0);
		move_chain(axx, -1, 0);
		if(y == 1)
			ft_putstr("pa ");
	}
}

void s_a(t_content *axx, int y)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit!= 0)
	{
		PUSH2(0, 0);
		move_chain(axx, -1, -2);
		if(y == 1)
			ft_putstr("sa ");
	}
}

void s_b(t_content *axx, int y)
{
	if(((t_clist*)LIST_V(1, 1) + 3)->bit!= 0)
	{
		PUSH2(1, 1);
		move_chain(axx, -1, -2);
		if(y == 1)
			ft_putstr("sb ");
	}
}

void ss(t_content *axx, int y)
{
	s_b(axx, 0);
	s_a(axx, 0);
	if(y == 1)
		ft_putstr("ss ");
}

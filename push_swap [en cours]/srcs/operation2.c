/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 17:58:21 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/01 03:48:07 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void r_a(t_content *axx, int y)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit != 0)
	{
		PUSH2(0,0);
		move_chain(axx, 0, -1);
		if(y == 1)
			ft_putstr("ra ");
	}
}

void r_b(t_content *axx, int y)
{
	if(((t_clist*)LIST_V(1, 1) + 3)->bit != 0)
	{
		PUSH2(1,1);
		move_chain(axx, 0, -1);
		if(y == 1)
			ft_putstr("rb ");

	}
}

void rr(t_content *axx, int y)
{
	r_a(axx, 0);
	r_b(axx, 0);
	if(y == 1)
		ft_putstr("rr ");

}

void rra(t_content *axx, int y)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit != 0)
	{
		PUSH2(0,0);
		move_chain(axx, 0, 2);
		if(y == 1)
			ft_putstr("rra ");
	}
}

void rrb(t_content *axx, int y)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit != 0)
	{
		PUSH2(1,1);
		move_chain(axx, 0, 2);
		if(y == 1)
			ft_putstr("rrb ");
	}

}

void rrr(t_content *axx, int y)
{
	rrb(axx, 0);
	rra(axx, 0);
	if(y == 1)
		ft_putstr("rrr ");
}

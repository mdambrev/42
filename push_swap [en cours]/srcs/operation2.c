/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 17:58:21 by mdambrev          #+#    #+#             */
/*   Updated: 2015/05/27 13:17:46 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void r_a(t_content *axx)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit != 0)
	{
		PUSH2(0,0);
		move_chain(axx, 0, -1);
	}
}

void r_b(t_content *axx)
{
	if(((t_clist*)LIST_V(1, 1) + 3)->bit != 0)
	{
		PUSH2(1,1);
		move_chain(axx, 0, -1);
	}
}

void rr(t_content *axx)
{
	r_a(axx);
	r_b(axx);
}

void rra(t_content *axx)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit != 0)
	{
		PUSH2(0,0);
		move_chain(axx, 0, 2);
	}
}

void rrb(t_content *axx)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit != 0)
	{
		PUSH2(1,1);
		move_chain(axx, 0, 2);
	}

}

void rrr(t_content *axx)
{
	rrb(axx);
	rra(axx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 20:14:51 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/01 03:58:33 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// atention a lincrementation parfois inutile si par ex pa ne fait rien

int op(t_content *axx, int x, int y)
{
	static int out = 0;

	if(x > 0)
		out++;
	else if(x == 0)
		s_a(axx, y);
	else if(x == 1)
		s_b(axx, y);
	else if(x == 2)
		ss(axx, y);
	else if(x == 3)
		p_a(axx, y);
	else if(x == 4)
		p_b(axx, y);
	else if(x == 5)
		r_a(axx, y);
	else if(x == 6)
		r_b(axx, y);
	else if(x == 7)
		rr(axx, y);
	else if(x == 8)
		rra(axx, y);
	else if(x == 9)
		rrb(axx, y);
	else if(x == 10)
		rrr(axx, y);
	return(out);
}

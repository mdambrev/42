/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 20:14:51 by mdambrev          #+#    #+#             */
/*   Updated: 2015/05/29 20:29:15 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int op(int x, int y);
{
	static int x = 0;

	if(x > 0)
		x++;
	if(x == 0)
		s_a(axx, y);
	if(x == 1)
		s_b(axx, y);
	if(x == 2)
		p_a(axx, y);
	if(x == 3)
		p_b(axx, y);
	if(x == 4)
		r_a(axx, y);
	if(x == 5)
		r_b(axx, y);
	if(x == 6)
		rr(axx, y);
	if(x == 7)
		rra(axx, y);
	if(x == 8)
		rrb(axx, y);
	if(x == 9)
		rrr(axx, y);
	return(x);
}

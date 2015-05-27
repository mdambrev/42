/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 15:04:40 by mdambrev          #+#    #+#             */
/*   Updated: 2015/05/27 12:57:46 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void p_b(t_content *axx)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit!= 0)
	{
		PUSH2(0, 1);
		move_chain(axx, -1, 0);
	}
}

void p_a(t_content *axx)
{
	if(((t_clist*)LIST_V(1, 1) + 3)->bit!= 0)
	{
		PUSH2(1, 0);
		move_chain(axx, -1, 0);
	}
}

void s_a(t_content *axx)
{
	if(((t_clist*)LIST_V(0, 1) + 3)->bit!= 0)
	{
		PUSH2(0, 0);
		move_chain(axx, -1, -2);
	}
}

void s_b(t_content *axx)
{
	if(((t_clist*)LIST_V(1, 1) + 3)->bit!= 0)
	{
		PUSH2(1, 1);
		move_chain(axx, -1, -2);
	}
}

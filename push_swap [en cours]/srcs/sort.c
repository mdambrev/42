/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:20:36 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/15 18:36:54 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int					cmp2(int a, int b)
{
	return (a < b);
}

int					check_list(t_content *axx, int n_list)
{
	int				x;

	x = 1;
	TMP_A(6) = LIST_A(n_list);
	while (LIST_IB(NB_LIST + 6, 0) == 0)
	{
		if (TMP_I(6, 0) < TMP_IN(6, 0) || TMP_V(6, 0) == TMP_V(6, 2))
			break ;
		x++;
	}
	if (TMP_V(6, 0) == TMP_V(6, 2))
		return (0);
	return (x);
}

int					pos_x(t_content *axx, int nb)
{
	int				x;

	x = 0;
	TMP_A(5) = LIST_A(0);
	LIST_R(NB_LIST + 5);
	while (LIST_IB(NB_LIST + 5, 0) == 0)
	{
		x++;
		if (TMP_I(5, 0) == nb)
			break ;
	}
	return (x);
}

void				result(t_content *axx)
{
	TMP_A(4) = LIST_A(0);
	TMP_A(5) = LIST_A(1);
	ft_putstr("\npa = {  ");
	while (LIST_IB(NB_LIST + 4, 0) == 0)
	{
		ft_putnbr(TMP_I(4, 0));
		ft_putstr("  ;  ");
	}
	ft_putendl("  }");
	ft_putstr("\npb = {  ");
	while (LIST_IB(NB_LIST + 5, 0) == 0)
	{
		ft_putnbr(TMP_I(5, 0));
		ft_putstr("  ;  ");
	}
	ft_putendl("  }");
}

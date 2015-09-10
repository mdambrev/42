/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 16:25:19 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/15 17:39:31 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sort_list_bul(t_content *axx, int nlist, int (*cmp)(int, int))
{
	int	x;

	x = 0;
	TMP_A(0) = LIST_A(nlist);
	while (LIST_IB(NB_LIST, 0) == 0)
	{
		TMP_A(1) = TMP_A(0);
		while (LIST_IB(NB_LIST + 1, 0) == 0)
		{
			if (cmp(TMP_I(0, 0), TMP_I(1, 0)) != 0)
			{
				x = TMP_I(0, 0);
				TMP_I(0, 0) = TMP_I(1, 0);
				TMP_I(1, 0) = x;
			}
		}
	}
}

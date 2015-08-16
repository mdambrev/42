/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:25:44 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/15 16:39:10 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

static void		norm(t_content *axx, int x)
{
	TMP_A(4) = LIST_A(1);
	LIST_R(NB_LIST + 4);
	while (LIST_IB(NB_LIST + 4, 0) == 0)
	{
		TMP_A(4) = LIST_A(1);
		LIST_R(NB_LIST + 4);
		op(axx, 3);
	}
	if (VALUE_I(2, 0) != 1)
	{
		if (x == 3)
			result(axx);
		ft_putstr("\n========================\n");
		ft_putstr("nb_coup : ");
		ft_putnbr((int)op(axx, -1));
		ft_putstr("\n");
	}
}

int				main(int argc, char **argv)
{
	t_content	*axx;
	int			x;

	x = 1;
	if (argv[1] && argv[1][0] == '-' && ft_isdigit(argv[1][1]) == 0)
	{
		if ((x = set_option(argv[1])) == -1)
			return (0);
		argv++;
		argc--;
	}
	verif_error(argv++);
	if (argc <= 2)
		return (0);
	axx = create_list(argv, argc);
	VALUE_I(2, 0) = x;
	tri_basic(axx);
	norm(axx, x);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 12:49:11 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/15 16:36:57 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int				cmp(int a, int b)
{
	return (a > b);
}

static	void	norm(t_content *axx, char **argv, int x)
{
	t_int		*tmp;

	tmp = (t_int*)malloc(sizeof(tmp));
	tmp->t_x = ft_atoi(argv[x]);
	add_l(&LIST_A(0), tmp, -1);
	tmp = (t_int*)malloc(sizeof(tmp));
	tmp->t_x = ft_atoi(argv[x]);
	add_l(&LIST_A(2), tmp, -1);
}

t_content		*create_list(char **argv, int argc)
{
	t_content	*axx;
	int			x;
	t_int		*tmp;

	x = 0;
	axx = init_list();
	add_l(&LIST_A(0), NULL, 0);
	tmp = (t_int*)malloc(sizeof(tmp));
	tmp->t_x = argc;
	LIST_V(0, 3) = tmp;
	tmp = (t_int*)malloc(sizeof(tmp));
	tmp->t_x = 0;
	add_l(&LIST_A(2), NULL, 0);
	LIST_V(2, 3) = tmp;
	while (argv[x])
	{
		norm(axx, argv, x);
		x++;
	}
	sort_list_bul(axx, 2, cmp);
	add_l(&LIST_A(1), NULL, 0);
	tmp = (t_int*)malloc(sizeof(tmp));
	tmp->t_x = 1;
	LIST_V(1, 3) = tmp;
	return (axx);
}

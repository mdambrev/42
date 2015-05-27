/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 12:49:11 by mdambrev          #+#    #+#             */
/*   Updated: 2015/05/27 15:13:40 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_content		*create_list(char **argv)
{
	t_content *axx;
	int x;
	t_int *tmp;

	x = 0;
	axx = init_list();
	while(argv[x])
	{
		tmp = (t_int*)malloc(sizeof(tmp));
		tmp->t_x = ft_atoi(argv[x]);
		add_l(&LIST_A(0), tmp, -1);
		x++;
	}
	add_l(&LIST_A(1), NULL, 0);
	return(axx);
}

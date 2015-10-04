/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 15:29:49 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/04 17:34:18 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <stdio.h>

char **split_path(t_clist *param)
{
	char **tab;
	t_content *axx;
	int x;

	x = 0 ;

	axx = PARAM(2);
	while(LIST_IB(0,0) == 0)
	{
		if(ft_strcmp(VALUE_C(0, 1), "PATH") == 0)
			break;
	}
	tab = ft_strsplit(VALUE_C(0, 0) + 5, ':');
	return(tab);
}

void	ret_bin(t_clist *param)
{
	char **tab;
	char **name;
	char *tmp2;
	char *tmp;
	int x;

	x = 0;
	tab = split_path(param);
	name = PARAM(1);
	
	while(tab[x])
	{
		tmp = ft_strjoin(tab[x], "/");
		tmp2 = ft_strjoin(tmp, name[0]);
		if(access(tmp2, X_OK) == 0)
			PARAM(3) = tmp2;
		x++;
	}
}

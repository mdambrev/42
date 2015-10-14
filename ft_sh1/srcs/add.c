/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 13:04:15 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/14 15:07:58 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int search_env(t_clist *param, char *name)
{
	t_content *axx;
	int x;

	axx = PARAM(2);
	TMP_A(5) =  LIST_A(0);
	LIST_R(NB_LIST + 5);
	x = 0;
	while(LIST_IB(NB_LIST + 5, 0) == 0)
	{
		x++;
		if(ft_strcmp(name, TMP_C(5, 1)) == 0)
			return(x);
	}
	return(0);
}

int add_env(t_clist *param, char *name, char *content)
{
	t_content *axx;

	axx = PARAM(2);
	if(search_env(param, name) > 0)
		return(0);
	add_l(&TMP_A(5), ft_strjoin(name, content), -1);
	add_lstr(&TMP_A(5), -1, 1, ft_strdup(name));
	return(1);
}

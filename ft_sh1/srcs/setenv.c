/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 11:39:18 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/08 12:19:09 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <stdio.h>

static int verif_alph(char *str)
{
	int x;

	x = 0;
	while(x < search_occu(str, '='))
	{
		if(str[x] > 90 || str[x] < 65)
			return(0);
		x++;
	}
	return(1);
}

int verif_arg(char **tab)
{
	if(!tab[1])
	{
		printf("put_error1\n");
		return(0);
	}
	if(search_occu(tab[1], '=') == (int)ft_strlen(tab[1]))
	{
		printf("put_error2\n");
		return(0);
	}
	if(verif_alph(tab[1]) == 0)
	{
		printf("put_error3\n");
		return(0);
	}
	if(tab[1][search_occu(tab[1], '=') + 1] == '\0')
	{
		printf("put_error4\n");
		return(0);
	}
	return(1);
}

void ft_setenv(t_clist *param)
{
	t_content *axx;
	char **tab;
	char *str;

	tab = PARAM(1);
	axx = PARAM(2);
	if(verif_arg(tab) == 0)
		return;
	str = ft_strsub(tab[1], 0, search_occu(tab[1], '='));
	TMP_A(3) = LIST_A(0);
	while(LIST_IB(NB_LIST + 3,0) == 0)
	{	
		if(ft_strcmp(TMP_C(3,1), str) == 0)
		{
			TMP_C(3,0) = ft_strdup(tab[1]);
			return;
		}
	}
	LIST_R(NB_LIST + 3);
	add_l(&TMP_A(3), ft_strdup(tab[1]), -1);
	add_lstr(&TMP_A(3), -1, 1, ft_strdup(str));
}

void ft_unsetenv(t_clist *param)
{
	
	t_content *axx;
	char	**tab;
	int		x;

	axx = PARAM(2);
	tab = PARAM(1);
	if(!tab[1])
		return;
	TMP_A(5) = LIST_A(0);
	LIST_R(NB_LIST + 5);
	x = 0;
	while(LIST_IB(NB_LIST + 5, 0) == 0)
	{
		if(ft_strcmp(TMP_C(5, 1), tab[1]) == 0)
		{
			LIST_R(NB_LIST + 5);
			del_elem(axx, NB_LIST + 5, x + 1, 0);
			return;
		}
		x++;
	}
	ft_putstr(tab[1]);
	ft_putendl(" : doesnt exist");
}

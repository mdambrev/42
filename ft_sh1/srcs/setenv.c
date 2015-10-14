/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 11:39:18 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/14 17:14:23 by mdambrev         ###   ########.fr       */
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
	char *content;
	char *name;

	tab = PARAM(1);
	axx = PARAM(2);
	if(verif_arg(tab) == 0)
		return;
	name = ft_strsub(tab[1], 0, search_occu(tab[1], '='));
	content = ft_strdup(tab[1] + search_occu(tab[1], '='));
	if(add_env(param, name, content) == 0)
		TMP_C(5, 0) = ft_strdup(tab[1]);	
}

void ft_unsetenv(t_clist *param)
{
	
	t_content *axx;
	char	**tab;
	int		x;

	tab = PARAM(1);
	axx = PARAM(2);
	if((x = search_env(param, tab[1])) > 0)
		del_elem(axx, NB_LIST + 5, x, 0);
	else
	{
		ft_putstr(tab[1]);
		ft_putendl(" : doesnt exist");
	}
}

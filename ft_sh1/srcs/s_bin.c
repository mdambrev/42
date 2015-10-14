/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 15:29:49 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/14 12:17:33 by mdambrev         ###   ########.fr       */
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
	TMP_A(1) = LIST_A(0);
	LIST_R(NB_LIST + 1);	
	while(LIST_IB(NB_LIST + 1, 0) == 0)
	{
		if(ft_strcmp(TMP_C(1, 1), "PATH") == 0)
		{
			tab = ft_strsplit(TMP_C(1, 0) + 5, ':');
			return(tab);
		}
	}
	return(NULL);
}

int		ret_bin(t_clist *param)
{
	char **tab;
	char **name;
	char *tmp2;
	char *tmp;
	int x;

	x = 0;
	tab = split_path(param);
	name = PARAM(1);
	if(access(name[CONTENT(0)], X_OK) == 0)
	{
		PARAM(3) = ft_strdup(name[CONTENT(0)]) ;
		return(1);
	}
	while(tab && tab[x])
	{
		tmp = ft_strjoin(tab[x], "/");
		tmp2 = ft_strjoin(tmp, name[CONTENT(0)]);
		if(access(tmp2, X_OK) == 0)
		{
			PARAM(3) = ft_strdup(tmp2);
			return(1);
		}
		x++;
	}
	return(0);
}

void 	set_action(t_clist *param, int order_tab)
{
	CONTENT(0) =  order_tab;
	if(set_builds(param) == 1)
		CONTENT(1) = 2;
	else if(ret_bin(param) == 1)
	{
		CONTENT(1) = 1;
		CONTENT(2) = 0;
	}
	else
	{
		CONTENT(1) = 0;
		CONTENT(2) = 0;
		if(PARAM(3))
			free(PARAM(3));
		PARAM(3) = NULL;
	}
}

void exec_bin(t_clist *param)
{
	char **env;
	char **args;
	int x;

	x = 0;
	args = PARAM(1);
	env = (char **)list_to_tab(PARAM(2), 0, 1, 0);
	execve(PARAM(3), args,env);
	exit(0);
}

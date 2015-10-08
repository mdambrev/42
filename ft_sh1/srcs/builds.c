/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 09:14:40 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/08 17:56:51 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>

int set_builds(t_clist *param)
{
	char **tab;

	tab = PARAM(1);
	if(ft_strcmp(tab[0], "cd") == 0)
		CONTENT(2) = 1;
	else if(ft_strcmp(tab[0], "setenv") == 0)
		CONTENT(2) = 2;
	else if(ft_strcmp(tab[0], "unsetenv") == 0)
		CONTENT(2) = 3;
	else if(ft_strcmp(tab[0], "env") == 0)
		CONTENT(2) = 4;
	else if(ft_strcmp(tab[0], "exit") == 0)
		CONTENT(2) = 5;
	else
	{
		CONTENT(2) = 0;
		return(0);
	}
	return(1);
}

void	put_env(t_clist *param)
{
	t_content *axx;

	axx = PARAM(2);
	TMP_A(0) = LIST_A(0);
	LIST_R(NB_LIST);
	while(LIST_IB(NB_LIST , 0) == 0)
	{
		ft_putendl(TMP_C(0, 0));
	}
}

void	exec_builtins(t_clist *param)
{
	if(CONTENT(2) == 4)
		put_env(param);
	if(CONTENT(2) == 2)
		ft_setenv(param);
	if(CONTENT(2) == 3)
		ft_unsetenv(param);
	if(CONTENT(2) == 5)
		exit(0);
	if(CONTENT(2) == 1)
		ft_cd(param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/10 13:00:27 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/10 18:31:57 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <stdio.h>

int set_old_pwd(t_clist *param, char *str)
{
	t_content *axx;

	axx = PARAM(2);
	TMP_A(2) = LIST_A(0);
	LIST_R(NB_LIST);
	while(LIST_IB(NB_LIST + 2, 0) == 0)
	{
		if(ft_strcmp(TMP_C(2,1), "OLDPWD") == 0)
		{
	//		printf("%s\n", ft_strjoin(TMP_C(2,1), str) bug == pwd = oldpwd
			TMP_C(2,0) = ft_strjoin(TMP_C(2,1), str);
			return(1);
		}
	}
	return(0);
}

char *search_home(t_clist *param)
{
	t_content *axx;

	axx = PARAM(2);
	TMP_A(0) = LIST_A(0);
	LIST_R(NB_LIST);
	while(LIST_IB(NB_LIST, 0) == 0)
	{
		if(ft_strcmp(TMP_C(0,1), "HOME") == 0)
		{
			return(ft_strsub(TMP_C(0, 0), 5, ft_strlen(TMP_C(0,0) + 5)));
		}
	}
	return(NULL);
}

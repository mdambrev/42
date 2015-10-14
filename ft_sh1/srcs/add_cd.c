/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/10 13:00:27 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/14 14:51:04 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <stdio.h>

int set_old_pwd(t_clist *param, char *str)
{
	t_content *axx;
	char *content;
	char *name;

	axx = PARAM(2);
	name = ft_strdup("OLDPWD");
	if(str[ft_strlen(str) - 2] == '.' && str[ft_strlen(str) - 1] == '.')
		str = ft_strsub(str, 0, ft_strlen(str) - 2);
	content = ft_strjoin("=",str);
	if(add_env(param, name, content) == 0)
		TMP_C(5, 0) = ft_strjoin(name, str);	

	return(0);
}

char *search_home(t_clist *param)
{
	t_content *axx;

	axx = PARAM(2);
	if(search_env(param, ft_strdup("HOME")) > 0)
		return(ft_strsub(TMP_C(5, 0), 5, ft_strlen(TMP_C(5,0) + 5)));

	return(NULL);
}

int verif_path_env(t_clist *param, char *path)
{
	t_content *axx;

	axx = PARAM(2);
	TMP_A(0) = LIST_A(0);
	LIST_R(NB_LIST);
	add_env(param, ft_strdup("PWD"), path);
	return(0);
}

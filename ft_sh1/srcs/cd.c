/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 15:50:11 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/14 17:40:17 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#include <dirent.h>

int 	verif_cd(char *path, t_clist *param)
{
	
	verif_path_env(param, path);
	if(opendir(path) == NULL)
		return(0);
	else 
		return(1);
}

void add_cwd(t_clist *param)
{
	t_content *axx;
	char *str;

	axx = PARAM(2);
	str = getcwd(NULL, 0);
	TMP_A(0) = LIST_A(0);
	while(LIST_IB(NB_LIST,0) == 0)
	{
		if(ft_strcmp(TMP_C(0, 1), "PWD") == 0)
		{
			set_old_pwd(param, TMP_C(0,0) + 3);
			TMP_C(0, 0) = ft_strjoin("PWD=", str);
			return;
		}
	}
	free(str);
}

void exec_pwd(char *path, t_clist *param)
{

	if(verif_cd(path, param) == 0)
		printf("error \n");
	else
	{
		chdir(path);	
		add_cwd(param);
	}
	
}

char	*join_path(t_clist *param, char *path)
{
	char *tmp;
	char **tab;
	t_content *axx;

	axx = PARAM(2);
	tab = PARAM(1);
	tmp = NULL;
	if(tab[1] != NULL && ft_strcmp(tab[1], "-") == 0)
	{
		if(search_env(param, "OLDPWD") > 0)
			tmp = ft_strdup(TMP_C(5,0) + 7);
		else
			ft_putendl("Error : Missing $OLDPWD");
		return(tmp);
	}
	if(tab[1] == NULL || ft_strcmp(tab[1], "~") == 0)
	{
		if((tmp = search_home(param)) != NULL)
			return(tmp);
		else
			ft_putendl("Error : Missing $HOME");
		return(tmp);
	}
	tmp = ft_strjoin(path, "/");
	path = ft_strjoin(tmp, tab[1]);
	return(path);
}


void	ft_cd(t_clist *param)
{
	char *path;
	char *tmp_path;
	char **tab;
	(void)param;

	tab = PARAM(1);
	path = NULL;
	if(opendir(tab[1]) != NULL)
		tmp_path = ft_strdup(tab[1]);
	else
	{
		path = getcwd(NULL, 0);
		if((tmp_path = join_path(param, path)) == NULL)
			return;
	}
	exec_pwd(tmp_path, param);
}

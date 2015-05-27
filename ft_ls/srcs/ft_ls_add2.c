/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_add2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 10:21:35 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:15:47 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				aff_total_l(t_list *liste, char *flux, char *option)
{
	struct stat		buf;
	int				x;
	char			*str;
	t_list			*tmp;

	tmp = liste;
	x = 0;
	if (option[1] == '1' && (flux || !flux) && liste->content != NULL)
	{
		while (tmp->next)
		{
			str = concac_flux((char *)tmp->content, flux);
			lstat(str, &buf);
			x = x + (int)buf.st_blocks;
			tmp = tmp->next;
		}
		ft_putstr("total ");
		ft_putnbr(x);
		ft_putstr("\n");
	}
}

int					cmp_tmp(char *str)
{
	struct stat		buf;
	double			x;

	lstat(str, &buf);
	x = buf.st_mtimespec.tv_sec;
	if (time(NULL) - x > 15778433 || time(NULL) - x < -3600)
		return (1);
	else
		return (0);
}

void				aff_symb(char *flux, char *content)
{
	struct stat		buf;
	size_t			x;
	char			*str;

	lstat(flux, &buf);
	ft_putstr(content);
	if (S_ISLNK(buf.st_mode))
	{
		x = (int)buf.st_size + 1;
		str = (char*)malloc(sizeof(char) * x + 1);
		readlink(flux, str, x);
		str[x - 1] = '\0';
		ft_putstr(" -> ");
		if (ft_strcmp(content, "stderr") == 0)
			ft_putstr("fd/2");
		if (ft_strcmp(content, "stdin") == 0)
			ft_putstr("fd/0");
		if (ft_strcmp(content, "stdout") == 0)
			ft_putstr("fd/1");
		ft_putstr(str);
	}
}

int					cmp_name(t_list *tab, char *content)
{
	static t_list	*tmp32;
	char			*str;
	static size_t	x32;

	if (tmp32 != tab)
	{
		tmp32 = tab;
		x32 = 0;
		if (content == NULL)
			content = ft_strdup(".");
		while (tab->next)
		{
			str = concac_flux((char*)tab->content, content);
			x32 = debug_user(str, x32);
			tab = tab->next;
		}
	}
	return (x32);
}

int					cmp_grp(t_list *tab, char *content)
{
	static	t_list	*tmp33;
	char			*str;
	static size_t	x33;

	if (tmp33 != tab)
	{
		tmp33 = tab;
		x33 = 0;
		if (content == NULL)
			content = ft_strdup(".");
		while (tab->next)
		{
			str = concac_flux((char*)tab->content, content);
			x33 = debug_grp(str, x33);
			tab = tab->next;
		}
	}
	return (x33);
}

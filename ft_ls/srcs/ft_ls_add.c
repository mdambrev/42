/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 18:57:16 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 17:53:03 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					times_comp(char *str1, char *str2, char *flux, char *o)
{
	struct stat		buf1;
	struct stat		buf2;
	char			*str_flux;

	if (!str1 || !str2)
		return (-1);
	str_flux = ft_strjoin(flux, "/");
	str1 = ft_strjoin(str_flux, str1);
	str2 = ft_strjoin(str_flux, str2);
	if (o[2] == '1')
	{
		str_flux = str1;
		str1 = str2;
		str2 = str_flux;
	}
	lstat(str1, &buf1);
	lstat(str2, &buf2);
	if (buf1.st_mtimespec.tv_sec > buf2.st_mtimespec.tv_sec)
		return (1);
	if (buf1.st_mtimespec.tv_sec == buf2.st_mtimespec.tv_sec)
		return (0);
	else
		return (2);
}

void				ls_tri_a_r(t_list **list)
{
	t_list			*tmp;
	size_t			content_size;
	void			*content;
	t_list			*tmp2;

	tmp = *list;
	tmp2 = *list;
	while (tmp && tmp2->content != NULL)
	{
		tmp = tmp2;
		while (tmp->content != NULL)
		{
			if (ft_strcmp((char*)tmp->content, (char*)tmp2->content) > 0)
			{
				content_size = tmp2->content_size;
				content = tmp2->content;
				tmp2->content_size = tmp->content_size;
				tmp2->content = tmp->content;
				tmp->content_size = content_size;
				tmp->content = content;
			}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
}

void				aff_time(char *content)
{
	struct stat		buf;
	char			*str;

	lstat(content, &buf);
	str = ctime(&buf.st_mtime);
	if (S_ISBLK(buf.st_mode) || S_ISCHR(buf.st_mode))
		special_file(content);
	if (cmp_tmp(content) == 0)
		ft_putstr(ft_strsub(str, 3, 13));
	else
	{
		ft_putstr(ft_strsub(str, 3, 8));
		ft_putstr(" ");
		ft_putstr(ft_strsub(str, 20, 4));
	}
}

char				*concac_flux(char *content, char *flux)
{
	char			*str1;
	char			*str2;

	if (flux == NULL)
		flux = ft_strdup(".");
	str1 = ft_strjoin(flux, "/");
	str2 = ft_strjoin(str1, content);
	return (str2);
}

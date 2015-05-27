/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_exclude.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 13:57:28 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:00:27 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t				debug_user(char *str, size_t x)
{
	struct stat		buf;
	struct passwd	*pw;
	size_t			y;

	lstat(str, &buf);
	if (!(pw = getpwuid(buf.st_uid)))
		y = ft_nbrlen(buf.st_uid);
	else
		y = ft_strlen(pw->pw_name);
	if (y > x)
		return (y);
	else
		return (x);
}

size_t				debug_grp(char *str, size_t x)
{
	struct stat		buf;
	struct group	*pw;
	size_t			y;

	lstat(str, &buf);
	if (!(pw = getgrgid(buf.st_gid)))
		y = ft_nbrlen(buf.st_gid);
	else
		y = ft_strlen(pw->gr_name);
	if (y > x)
		return (y);
	else
		return (x);
}

size_t				debug_link(char *str, size_t x)
{
	struct stat		buf;
	size_t			y;

	lstat(str, &buf);
	y = ft_nbrlen(buf.st_nlink);
	if (y > x)
		return (y);
	else
		return (x);
}

size_t				debug_octet(char *str, size_t x, int *y)
{
	struct stat		buf;
	size_t			lol;

	lstat(str, &buf);
	lol = ft_nbrlen(buf.st_size);
	if (S_ISBLK(buf.st_mode) || S_ISCHR(buf.st_mode))
		*y = 1;
	if (lol > x)
		return (lol);
	else
		return (x);
}

int					cmp_link(t_list *list, int y)
{
	struct stat		buf;
	struct passwd	*name;
	t_list			*tmp;
	struct group	*grp;
	size_t			x;

	x = 0;
	tmp = list;
	while (tmp->next)
	{
		lstat((char *)tmp->content, &buf);
		if (y == 1 && (name = getpwuid(buf.st_uid)))
		{
			if (ft_strlen(name->pw_name) > x)
				x = ft_strlen(name->pw_name);
		}
		else if (y == 2)
		{
			grp = getgrgid(buf.st_gid);
			if (ft_strlen(grp->gr_name) > x)
				x = ft_strlen(grp->gr_name);
		}
		tmp = tmp->next;
	}
	return (x);
}

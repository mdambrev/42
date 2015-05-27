/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_add4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 14:13:56 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 17:53:57 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				aff_user_link(char *str, int x, int y)
{
	int				a;
	int				b;
	struct stat		buf;
	struct passwd	*name;
	struct group	*grp;

	lstat(str, &buf);
	name = getpwuid(buf.st_uid);
	a = x - ft_strlen(name->pw_name) + 2;
	ft_putstr(name->pw_name);
	while (a-- > 0)
		ft_putstr(" ");
	grp = getgrgid(buf.st_gid);
	b = y - ft_strlen(grp->gr_name);
	ft_putstr(grp->gr_name);
	while (b-- > 0)
		ft_putstr(" ");
}

int					cmp_octet(t_list *liste)
{
	struct stat		buf;
	int				x;
	t_list			*tmp;

	tmp = liste;
	x = 0;
	while (tmp->next)
	{
		lstat((char *)liste->content, &buf);
		if (ft_nbrlen((int)buf.st_size) > x)
			x = ft_nbrlen(buf.st_size);
		tmp = tmp->next;
	}
	return (x);
}

void				put_octet(char *str, int z)
{
	struct stat		buf;
	int				x;

	lstat(str, &buf);
	x = z - ft_nbrlen(buf.st_size) + 2;
	while (x-- > 0)
		ft_putstr(" ");
	ft_putnbr(buf.st_size);
}

void				main_link(int argc, char **argv, char *option)
{
	t_list			*list;

	list = list_symb(argc, argv, option);
	aff_list_link(list);
}

t_list				*norm_t(t_list **list, char *option)
{
	t_list			*tmp2;

	tmp2 = *list;
	if (option[3] == '1' && option[2] == '1')
		ls_tri_a_r(&tmp2->next);
	else
		ls_tri_a(&tmp2->next);
	return (tmp2->next);
}

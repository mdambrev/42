/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_add3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 16:09:10 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 17:53:36 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				special_file(char *flux)
{
	struct stat		buf;
	int				major;
	int				minor;

	lstat(flux, &buf);
	major = MAJOR(buf.st_rdev);
	minor = MINOR(buf.st_rdev);
	if (ft_nbrlen(major) == 1)
		ft_putstr("  ");
	if (ft_nbrlen(major) == 2)
		ft_putstr(" ");
	ft_putnbr(major);
	ft_putstr(", ");
	if (ft_nbrlen(minor) == 1)
		ft_putstr("  ");
	if (ft_nbrlen(minor) == 2)
		ft_putstr(" ");
	if (ft_nbrlen(minor) == 3)
		ft_putstr("");
	ft_putnbr(minor);
}

int					test_symb(char *flux, int argc, char **argv)
{
	struct stat		buf;
	char			*str;

	str = option_main(argc, argv);
	lstat(flux, &buf);
	if (S_ISLNK(buf.st_mode) && str[1] == '1')
		return (0);
	else
		return (1);
}

t_list				*list_symb(int argc, char **argv, char *option)
{
	char			**tab;
	struct stat		buf;
	int				x;
	t_list			*list;
	t_list			*tmp;

	x = 0;
	list = ft_lstnew(NULL, 0);
	tab = args_order(argc, argv);
	while (tab[x])
	{
		if (lstat(tab[x], &buf) != -1)
		{
			if (S_ISLNK(buf.st_mode) == 1 && option[1] == '1')
			{
				tmp = ft_lstnew(tab[x], ft_strlen(tab[x]) + 1);
				ft_lstadd(&list, tmp);
			}
		}
		x++;
	}
	set_file_option(&list, option);
	return (list);
}

void				aff_list_link(t_list *liste)
{
	t_list			*tmp;
	int				x;
	int				y;
	int				z;

	z = cmp_octet(liste);
	x = cmp_link(liste, 1);
	y = cmp_link(liste, 2);
	tmp = liste;
	while (tmp->next)
	{
		aff_link2(tmp, x, y, z);
		tmp = tmp->next;
		ft_putstr("\n");
	}
}

void				aff_link2(t_list *tab, int x, int y, int z)
{
	char			*str;
	t_list			*tmp;

	tmp = tab;
	ft_putstr((str = main_parse((char *)tmp->content)));
	ft_putstr("  1 ");
	aff_user_link((char *)tmp->content, x, y);
	put_octet((char *)tmp->content, z);
	aff_time((char *)tmp->content);
	ft_putstr(" ");
	aff_symb((char *)tmp->content, (char *)tab->content);
}

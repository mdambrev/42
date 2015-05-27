/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_forms_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:02:08 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:01:34 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int						len_octet_max(t_list *liste, char *flux, int *z)
{
	static t_list		*tmp35;
	char				*str;
	static size_t		x35;
	static int			y;

	if (tmp35 != liste)
	{
		y = 0;
		tmp35 = liste;
		x35 = 0;
		while (liste->next)
		{
			str = concac_flux((char *)liste->content, flux);
			x35 = debug_octet(str, x35, &y);
			liste = liste->next;
		}
	}
	*z = y;
	return (x35);
}

int						len_link_max(t_list *liste, char *flux)
{
	static t_list		*tmp34;
	char				*str;
	static size_t		x34;

	if (tmp34 != liste)
	{
		tmp34 = liste;
		x34 = 0;
		while (liste->next)
		{
			str = concac_flux((char *)liste->content, flux);
			x34 = debug_link(str, x34);
			liste = liste->next;
		}
	}
	return (x34);
}

void					aff_option(char *flux,
		char *content, char *option, t_list *tab)
{
	char				*str;

	if (option[1] == '0')
		ft_putendl((char *)content);
	else if (option[1] == '1')
	{
		str = concac_flux(content, flux);
		ft_putstr(main_parse(str));
		aff_link(tab, flux, str);
		ft_putstr(" ");
		aff_user_grp(str, flux, tab);
		aff_octet(tab, flux, str);
		aff_time(str);
		ft_putstr(" ");
		aff_symb(str, content);
		ft_putstr("\n");
	}
}

void					aff_octet(t_list *tab, char *content, char *flux)
{
	struct stat			buf;
	int					x;
	int					y;
	int					z;

	lstat(flux, &buf);
	y = (int)buf.st_size;
	if (content != NULL)
		x = len_octet_max(tab, content, &z) + 2 - ft_nbrlen(y);
	else
		x = len_octet_max(tab, ".", &z) + 2 - ft_nbrlen(y);
	if (!S_ISBLK(buf.st_mode) && !S_ISCHR(buf.st_mode) && z)
		x = x + 7;
	while (x-- > 0)
		ft_putstr(" ");
	if (!S_ISBLK(buf.st_mode) && !S_ISCHR(buf.st_mode))
		ft_putnbr(y);
}

void					aff_link(t_list *tab, char *content, char *flux)
{
	struct stat			buf;
	int					x;
	int					y;

	lstat(flux, &buf);
	y = (int)buf.st_nlink;
	if (content != NULL)
		x = len_link_max(tab, content) + 2 - ft_nbrlen(y);
	else
		x = len_link_max(tab, ".") + 2 - ft_nbrlen(y);
	while (x-- > 0)
		ft_putstr(" ");
	ft_putnbr(y);
}

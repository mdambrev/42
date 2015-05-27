/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_form_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:13:47 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:01:05 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_n(char *str2, t_list *tab, char *option, t_list *argv)
{
	if (option[0] == '0')
	{
		if (((char*)(argv->content))[0] != '.')
		{
			ft_putstr("\n");
			ft_putstr(str2);
			ft_putstr(":\n");
			aff_list_(tab, -1, str2, option);
		}
		if (!option)
			write(1, "0", 1);
	}
	else
	{
		ft_putstr("\n");
		ft_putstr(str2);
		ft_putstr(":\n");
		aff_list_(tab, 0, str2, option);
	}
}

void				aff_list_r_(t_list *argv, char *option, char *bob)
{
	struct stat		buf;
	t_list			*tab;
	char			*str;
	char			*str2;

	while (argv->content != NULL && argv)
	{
		str = ft_strjoin(bob, "/");
		str2 = ft_strjoin(str, argv->content);
		lstat(str2, &buf);
		if (S_ISDIR(buf.st_mode) && !ft_strequ(argv->content, ".")
			&& !ft_strequ(argv->content, "..") && error_mod(str2))
		{
			tab = ls_(str2, option);
			ls_tri_main(&tab, option, str2);
			ft_n(str2, tab, option, argv);
			aff_list_r_(tab, option, str2);
		}
		argv = argv->next;
	}
}

void				aff_all_r_(t_list **tab, int argc, char **argv)
{
	int				x;
	int				y;
	char			**ret;
	char			*option;
	int				z;

	ret = test_args(argc, argv);
	option = option_main(argc, argv);
	if ((x = 0) == 0 && option[0] == '1')
		z = 1;
	else
		z = -1;
	if ((y = nb_true_args(argc, argv)) == 0 && nb_path(argc, argv) == 0)
	{
		aff_list_(tab[x], z, ".", option);
		aff_list_r_(tab[x], option, ".");
	}
	while (tab[x] != NULL && x < y)
	{
		aff_list_(tab[x], z, ret[x], option);
		aff_list_r_(tab[x], option, ret[x]);
		x++;
		if (x < y && tab[x] != NULL)
			ft_putstr("\n");
	}
}

int					error_mod(char *flux)
{
	DIR				*rep;
	struct stat		buf;

	if ((rep = opendir(flux)) == NULL && (lstat(flux, &buf) == 0
			&& S_ISDIR(buf.st_mode) == 1))
	{
		ft_putstr("\n");
		ft_putstr(flux);
		ft_putstr(":\nls: ");
		perror(flux);
		return (0);
	}
	else
	{
		closedir(rep);
		return (1);
	}
}

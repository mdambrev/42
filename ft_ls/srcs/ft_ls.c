/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 14:00:54 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:14:37 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			nb_path(int argc, char **argv)
{
	int		x;
	int		tab[2];
	int		y;

	tab[0] = 0;
	tab[1] = 0;
	x = 1;
	y = argc - 1;
	while (x < argc)
	{
		if (argv[x][0] != '-' || ft_strcmp(argv[x], "--") == 0)
		{
			if (ft_strcmp(argv[x], "--") == 0)
			{
				x++;
				tab[0]++;
			}
			break ;
		}
		tab[0]++;
		x++;
	}
	tab[1] = y - tab[0];
	return (tab[1]);
}

int			main(int argc, char **argv)
{
	char	*option;
	t_list	**tab;

	option = option_main(argc, argv);
	main_error(argc, argv, option);
	main_link(argc, argv, option);
	main_file(argc, argv, option);
	tab = set_option(option, argc, argv);
	if (option[4] != '1')
		aff_all_list(tab, argc, argv);
	else
		aff_all_r_(tab, argc, argv);
	return (0);
}

void		aff_user_grp(char *flux, char *content, t_list *tab)
{
	char	*tmp;
	char	*tmp2;
	size_t	x;

	tmp = aff_user(flux);
	x = 0;
	if (!tab || !content)
		;
	x = cmp_name(tab, content) - ft_strlen(tmp) + 2;
	while (x-- > 0)
		ft_putstr(" ");
	tmp2 = aff_grp(flux);
	x = cmp_grp(tab, content) - ft_strlen(tmp2);
	while (x-- > 0)
		ft_putstr(" ");
}

char		*aff_user(char *str)
{
	struct stat		buf;
	struct passwd	*name;

	lstat(str, &buf);
	if (!(name = getpwuid(buf.st_uid)))
	{
		ft_putnbr(buf.st_uid);
		return (ft_itoa(buf.st_uid));
	}
	else
	{
		ft_putstr(name->pw_name);
		return (ft_strdup(name->pw_name));
	}
}

char		*aff_grp(char *str)
{
	struct stat		buf;
	struct group	*gr;

	lstat(str, &buf);
	if (!(gr = getgrgid(buf.st_gid)))
	{
		ft_putnbr(buf.st_gid);
		return (ft_itoa(buf.st_gid));
	}
	else
	{
		ft_putstr(gr->gr_name);
		return (ft_strdup(gr->gr_name));
	}
}

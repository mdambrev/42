/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:53:07 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:02:08 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			nb_option(int argc, char **argv)
{
	int		x;

	x = 1;
	if (argc > 1)
	{
		while (x != argc && argv[x][0] == '-'
				&& !((argv[x][0] == '-' && argv[x][1] == '-')
					&& ft_strcmp(argv[x], "--") == 0))
			x++;
		return (x - 1);
	}
	return (0);
}

char		*option_ls(int argc, char **argv)
{
	char	**tab;
	int		x;
	int		y;
	char	*str;

	x = 1;
	y = nb_option(argc, argv);
	if (y < 1)
		return (NULL);
	tab = (char **)malloc(sizeof(char*) * y + 2);
	while (x <= y)
	{
		tab[x - 1] = argv[x];
		x++;
	}
	str = join_option(tab, y);
	str = del_dup(str);
	return (str);
}

char		*join_option(char **tab, int y)
{
	int		x;
	char	*tmp1;
	char	*tmp2;

	x = 2;
	if (y == 1)
	{
		tmp1 = ft_strdup(tab[0] + 1);
		return (tmp1);
	}
	tmp1 = ft_strjoin(tab[0] + 1, tab[1] + 1);
	tmp1 = del_dup(tmp1);
	while (x < y)
	{
		tmp2 = tmp1;
		tmp1 = ft_strjoin(tmp1, tab[x] + 1);
		tmp1 = del_dup(tmp1);
		x++;
	}
	return (tmp1);
}

char		*del_dup(char *str)
{
	char	*tmp;
	int		x;
	int		y;

	x = 0;
	tmp = (char*)malloc(sizeof(char*) * ft_strlen(str) + 2);
	tmp[0] = '\0';
	while (str[x])
	{
		y = 0;
		while (str[x] != tmp[y] && tmp[y])
			y++;
		if (tmp[y] == '\0')
		{
			tmp[y] = str[x];
			tmp[y + 1] = '\0';
		}
		x++;
	}
	return (tmp);
}

char		*ft_norm(char *str, char **add)
{
	ft_putstr("ls : illegal option -- ");
	ft_putchar(*str);
	if (add)
		;
	ft_putstr("\nusage: ls [-Rart1] [file ...]\n");
	return (NULL);
}

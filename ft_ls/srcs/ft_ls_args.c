/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 00:33:03 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 17:54:13 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			**args_ls(int argc, char **argv)
{
	char		**tab;
	int			x;
	int			y;

	y = 0;
	if (argc <= 1)
		return (NULL);
	x = nb_path(argc, argv);
	tab = (char **)malloc(sizeof(char*) * x + 1);
	while (y < x)
	{
		tab[y] = argv[argc - 1 - y];
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

char			*min_args(char **tab, int size)
{
	int			x;
	char		*tmp;

	x = 0;
	if (tab == NULL)
		return (NULL);
	if (size == 1)
		return (tab[0]);
	while (tab[x] == NULL)
		x++;
	tmp = tab[x];
	while (x < size)
	{
		if (tab[x] == NULL)
			;
		else if (ft_strcmp(tab[x], tmp) < 0)
			tmp = tab[x];
		x++;
	}
	x = 0;
	while (tab[x++] != tmp)
		;
	return (tmp);
}

char			**args_order(int argc, char **argv)
{
	char		**tab;
	char		**tmp;
	int			x;
	int			y;
	int			z;

	x = nb_path(argc, argv);
	y = 0;
	tmp = (char **)malloc(sizeof(char *) * x + 1);
	tab = args_ls(argc, argv);
	while (y < x)
	{
		tmp[y] = min_args(tab, x);
		z = 0;
		while (tab[z] != tmp[y])
			z++;
		tab[z] = NULL;
		y++;
	}
	tmp[y] = NULL;
	return (tmp);
}

char			**test_args(int argc, char **argv)
{
	int			x;
	int			y;
	char		**ret;
	DIR			*file;
	char		**args;

	x = 0;
	y = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * nb_path(argc, argv) + 2)))
		exit(-1);
	args = args_order(argc, argv);
	while (x < nb_path(argc, argv))
	{
		if ((file = opendir(args[x])) == NULL
				|| test_symb(args[x], argc, argv) == 0)
		{
			x++;
			continue;
		}
		ret[y++] = args[x++];
		if (closedir(file) == -1)
			exit(-1);
	}
	ret[y] = NULL;
	return (ret);
}

int				nb_true_args(int argc, char **argv)
{
	char		**tab;
	int			x;

	x = 0;
	tab = test_args(argc, argv);
	while (tab[x] != NULL)
	{
		x++;
	}
	return (x);
}

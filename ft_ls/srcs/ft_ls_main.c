/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 07:31:02 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:01:56 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*option_main(int argc, char **argv)
{
	char		*str;
	char		*option;

	str = option_ls(argc, argv);
	if ((option = verif_option(str)) == NULL)
	{
		exit(-1);
	}
	return (option);
}

void			ls_tri_main(t_list **list, char *option, char *flux)
{
	if (option[3] == '1' && option[2] == '1')
	{
		ls_tri_a_r(list);
		ls_tri_t(list, flux, option);
	}
	else if (option[3] == '1')
	{
		ls_tri_a(list);
		ls_tri_t(list, flux, option);
	}
	else if (option[2] == '1')
		ls_tri_a_r(list);
	else
		ls_tri_a(list);
}

t_list			**set_option(char *option, int argc, char **argv)
{
	char		**args;
	int			y;
	int			x;
	t_list		**tab;

	x = 0;
	y = nb_true_args(argc, argv);
	args = test_args(argc, argv);
	tab = (t_list**)malloc(sizeof(t_list*) * y + 2);
	while (x < y)
	{
		tab[x] = ls_(args[x], option);
		ls_tri_main(&tab[x], option, args[x]);
		x++;
	}
	tab[y] = ls_(".", option);
	ls_tri_main(&tab[y], option, ".");
	return (tab);
}

char			*verif_option(char *str)
{
	char	*add;

	add = ft_strnew_bin(5);
	while (str != NULL && *str)
	{
		if (*str == 'a')
			add[0] = '1';
		else if (*str == 'l')
			add[1] = '1';
		else if (*str == 'r')
			add[2] = '1';
		else if (*str == 't')
			add[3] = '1';
		else if (*str == 'R')
			add[4] = '1';
		else if (*str == '1')
			;
		else
			return (ft_norm(str, &add));
		str++;
	}
	return (add);
}

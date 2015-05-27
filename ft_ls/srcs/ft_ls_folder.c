/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_folder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:34:34 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:00:40 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_folder(t_list *liste, int argc, char **argv)
{
	t_list			*tmp;
	int				x;

	x = 0;
	tmp = liste;
	while (tmp)
	{
		ft_putendl((char*)tmp->content);
		tmp = tmp->next;
		x++;
	}
	if (x > 1 && nb_true_args(argc, argv) >= 1)
		write(1, "\n", 1);
}

t_list				*create_list_folder(int argc, char **argv)
{
	int				x;
	char			**tab;
	t_list			*list;
	t_list			*tmp;
	char			*str;

	x = 0;
	str = option_main(argc, argv);
	tab = args_order(argc, argv);
	list = ft_lstnew(NULL, 0);
	while (tab[x])
	{
		if (test_files(tab[x], str) == 1)
		{
			tmp = ft_lstnew(tab[x], ft_strlen(tab[x]) + 1);
			ft_lstadd(&list, tmp);
		}
		x++;
	}
	return (list);
}

int					test_files(char *flux, char *str)
{
	DIR				*rep;
	struct stat		buf;

	if ((rep = opendir(flux)) == NULL)
	{
		if (lstat(flux, &buf) == 0 && S_ISDIR(buf.st_mode) == 0 &&
			!(S_ISLNK(buf.st_mode) == 1 && str[1] == '1'))
			return (1);
	}
	else
		closedir(rep);
	return (0);
}

void				set_file_option(t_list **list, char *option)
{
	if (option[3] == '1' && option[2] == '1')
	{
		ls_tri_a_r(list);
		ls_tri_t(list, ".", option);
	}
	else if (option[3] == '1')
	{
		ls_tri_a(list);
		ls_tri_t(list, ".", option);
	}
	else if (option[2] == '1')
		ls_tri_a_r(list);
	else
		ls_tri_a(list);
}

void				main_file(int argc, char **argv, char *option)
{
	t_list			*list;

	list = create_list_folder(argc, argv);
	set_file_option(&list, option);
	print_folder(list, argc, argv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 19:53:28 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:00:10 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_error(t_list *liste)
{
	t_list		*tmp;
	DIR			*rep;

	tmp = liste;
	while (tmp->next)
	{
		if ((rep = opendir((char*)tmp->content)) == NULL)
		{
			ft_putstr("ls: ");
			perror((char*)tmp->content);
		}
		tmp = tmp->next;
	}
}

t_list			*create_list_error(int argc, char **argv)
{
	int			x;
	char		**tab;
	t_list		*list;
	t_list		*tmp;

	x = 0;
	tab = args_order(argc, argv);
	list = ft_lstnew(NULL, 0);
	while (tab[x])
	{
		if (test_error(tab[x]) == 1)
		{
			tmp = ft_lstnew(tab[x], ft_strlen(tab[x]) + 1);
			ft_lstadd(&list, tmp);
		}
		x++;
	}
	return (list);
}

int				test_error(char *flux)
{
	DIR			*rep;
	struct stat	buf;

	if ((rep = opendir(flux)) == NULL)
	{
		if (lstat(flux, &buf) == -1 ||
		(lstat(flux, &buf) == 0 && S_ISDIR(buf.st_mode) == 1))
			return (1);
	}
	else
		closedir(rep);
	return (0);
}

void			set_error_option(t_list **list, char *option)
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

void			main_error(int argc, char **argv, char *option)
{
	t_list *list;

	list = create_list_error(argc, argv);
	set_error_option(&list, option);
	print_error(list);
}

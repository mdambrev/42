/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_forms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 14:00:23 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:01:20 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list				*ls_(const char *flux, const char *option)
{
	DIR				*rep;
	struct dirent	*files;
	t_list			*list;
	t_list			*tmp;

	files = NULL;
	tmp = NULL;
	if ((rep = opendir(flux)) == NULL)
	{
		ft_putstr("ls :");
		perror(flux);
		return (NULL);
	}
	list = ft_lstnew(NULL, 0);
	while ((files = readdir(rep)) != NULL)
	{
		if (files->d_name[0] == '.' && option[0] != '1')
			continue ;
		tmp = ft_lstnew(ft_strdup(files->d_name), ft_strlen(files->d_name) + 1);
		ft_lstadd(&list, tmp);
	}
	if (closedir(rep) == -1)
		exit(-1);
	return (list);
}

void				ls_tri_a(t_list **list)
{
	t_list			*tmp;
	size_t			content_size;
	void			*content;
	t_list			*tmp2;

	tmp = *list;
	tmp2 = *list;
	while (tmp && tmp2->content != NULL)
	{
		tmp = tmp2;
		while (tmp->content != NULL)
		{
			if (ft_strcmp((char*)tmp->content, (char*)tmp2->content) < 0)
			{
				content_size = tmp2->content_size;
				content = tmp2->content;
				tmp2->content_size = tmp->content_size;
				tmp2->content = tmp->content;
				tmp->content_size = content_size;
				tmp->content = content;
			}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
}

void				aff_list_(t_list *tab, int y, char *argv, char *option)
{
	t_list			*tmp;
	t_list			*tmp2;

	tmp = tab;
	tmp2 = tab;
	if (y > 1)
	{
		ft_putstr(argv);
		ft_putendl(":");
	}
	aff_total_l(tmp2, argv, option);
	while (tmp->content != NULL)
	{
		if (!(y == -1 && ((char*)(tmp->content))[0] == '.'))
			aff_option(argv, (char *)tmp->content, option, tab);
		tmp = tmp->next;
	}
}

void				aff_all_list(t_list **tab, int argc, char **argv)
{
	int				x;
	int				y;
	char			**ret;
	char			*option;

	option = option_main(argc, argv);
	if ((y = nb_true_args(argc, argv)) == 0)
		y = 1;
	if (nb_path(argc, argv) > 0 && nb_true_args(argc, argv) == 0)
		return ;
	ret = test_args(argc, argv);
	x = 0;
	while (tab[x] != NULL && x < y)
	{
		aff_list_(tab[x], nb_path(argc, argv), ret[x], option);
		if (++x < y && tab[x] != NULL)
			ft_putstr("\n");
	}
}

void				ls_tri_t(t_list **list, char *flux, char *option)
{
	t_list			*tmp;
	size_t			content_size;
	void			*content;
	t_list			*tmp2;

	tmp2 = *list;
	while (tmp2 && tmp2->content != NULL)
	{
		tmp = tmp2->next;
		while (tmp->content != NULL)
		{
			if (times_comp((char*)tmp->content,
					(char*)tmp2->content, flux, option) == 1)
			{
				content_size = tmp2->content_size;
				content = tmp2->content;
				tmp2->content_size = tmp->content_size;
				tmp2->content = tmp->content;
				tmp->content_size = content_size;
				tmp->content = content;
			}
			tmp = tmp->next;
		}
		tmp2 = norm_t(&tmp2, option);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 16:33:30 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/02 02:14:10 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

t_clist						*init_param(void)
{
	t_clist					*param;
	t_int					*content;

	param = (t_clist *)malloc(sizeof(t_clist) * NB_PARAM + 10);
	content = (t_int *)malloc(sizeof(t_int) * NB_INT + 10);
	param->bit = content;
	free(PARAM(2));
	PARAM(2) = NULL;
	return (param);
}

int							ft_nb_list(int argc, char **argv)
{
	int						fd;
	char					*line;
	int						x;

	fd = 0;
	x = 0;
	line = NULL;
	if ((fd = open(argv[1], O_RDONLY)) == -1 || argc != 2)
	{
		exit(-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		x++;
		free(line);
		line = NULL;
	}
	free(line);
	return (x);
}

t_content					*create_list(int nb_list)
{
	t_content				*axx;
	int						x;

	x = 0;
	axx = (t_content *)ft_memalloc(sizeof(t_content) * nb_list);
	while (x < nb_list)
	{
		add_l(&LIST_A(x), NULL, 0);
		x++;
	}
	return (axx);
}

int							write_list(t_content *axx, char *line, int x)
{
	char					**tab;
	t_int					*tmp;
	t_int					tmp2;
	static int				len;
	static int				compteur = 0;

	x = 0;
	tab = ft_strsplit(line, ',');
	if (tab == NULL)
		exit(-1);
	tmp2.t_x = 0;
	tmp = &tmp2;
	LIST_V(0, 3) = tmp;
	while (tab[x])
	{
		tmp = (t_int*)malloc(sizeof(tmp) * NB_CONTENT + 5);
		tmp->t_x = ft_atoi(tab[x++]);
		add_l(&LIST_A(compteur), tmp, -1);
	}
	del_tab(&tab);
	if (len < x)
		len = x;
	compteur++;
	return (len);
}

t_content					*parsing(int argc, char **argv, int nb_list)
{
	int						fd;
	char					*line;
	t_content				*axx;
	int						x;
	int						len;

	fd = 0;
	x = 0;
	len = 0;
	axx = create_list(nb_list);
	if ((fd = open(argv[1], O_RDONLY)) == -1 || argc != 2)
		exit(-1);
	while (get_next_line(fd, &line) == 1)
	{
		len = write_list(axx, line, nb_list);
		free(line);
		line = NULL;
	}
	free(line);
	close(fd);
	LIST_R(0);
	VALUE_I(0, 0) = len;
	return (axx);
}

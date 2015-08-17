/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 16:33:30 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/17 20:13:01 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_nb_list(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		x;

	
	fd = 0;
	x = 0;
	if((fd = open(argv[1], O_RDONLY)) == -1 || argc != 2)
	{
		printf("Error Get_next_line \n");
		return(-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		x++;
		free(line);
		line = NULL;
	}
	return(x);
}

t_content *create_list(int nb_list)
{
	t_content *axx;
	int x;

	x = 0;
	axx = (t_content *)ft_memalloc(sizeof(t_content) * nb_list);
	while(x  < nb_list)
	{
		add_l(&LIST_A(x), NULL, 0);
		x++;
	}
	return (axx);
}

void write_list(t_content *axx, char *line)
{
	static int compteur = 0;
	char **tab;
	int x;
	t_int	*tmp;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while(tab[x])
	{
		tmp = (t_int*)malloc(sizeof(tmp) * NB_CONTENT);
		tmp->t_x = ft_atoi(tab[x]);
		add_l(&LIST_A(compteur), tmp, -1);
		x++;
	}
	compteur++;
}

t_content	 *parsing(int argc, char **argv, int nb_list)
{

	int		fd;
	char	*line;
	t_content *axx;
	int		x;

	
	fd = 0;
	x = 0;
	axx = create_list(nb_list);
	if((fd = open(argv[1], O_RDONLY)) == -1 || argc != 2)
	{
		printf("Error Get_next_line \n");
		return(NULL);
	}
	while (get_next_line(fd, &line) == 1)
	{
		write_list(axx, line);
		free(line);
		line = NULL;
	}
	close(fd);
	while(x < nb_list)
	{
		LIST_R(x);
		while(LIST_IB(x, 0) == 0)
			printf(" %d", VALUE_I(x, 0));
		printf("\n");
		x++;
	}
	return(axx);
}

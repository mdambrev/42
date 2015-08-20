/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 16:33:30 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/20 18:57:17 by mdambrev         ###   ########.fr       */
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
		exit(-1);
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

int write_list(t_content *axx, char *line)
{
	static int compteur = 0;
	char **tab;
	int x;
	t_int	*tmp;
	static int len;

	x = 0;
	tab = ft_strsplit(line, ' ');
	tmp = (t_int*)malloc(sizeof(tmp) * NB_CONTENT);
	tmp->t_x = 0;
	LIST_V(0, 3) = tmp;
	while(tab[x])
	{
		tmp = (t_int*)malloc(sizeof(tmp) * NB_CONTENT + 5);
		tmp->t_x = ft_atoi(tab[x]);
		add_l(&LIST_A(compteur), tmp, -1);
		x++;
	}
	if(len < x)
		len = x;
	compteur++;
	return(len);
}

t_content	 *parsing(int argc, char **argv, int nb_list)
{

	int		fd;
	char	*line;
	t_content *axx;
	int		x;
	int 	len;

	
	fd = 0;
	x = 0;
	len = 0;
	axx = create_list(nb_list);
	if((fd = open(argv[1], O_RDONLY)) == -1 || argc != 2)
	{
		printf("Error Get_next_line \n");
		exit(-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		len = write_list(axx, line);
		free(line);
		line = NULL;
	}
	close(fd);
	LIST_R(0);
	VALUE_I(0, 0) = len;
/*	while(x < nb_list)
	{
		LIST_R(x);
		while(LIST_IB(x, 0) == 0)
			printf(" %d", VALUE_I(x, 0));
		printf("\n");
		x++;
	}*/
	return(axx);
}

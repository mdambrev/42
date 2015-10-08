/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 09:30:09 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/08 15:34:59 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <stdio.h>

t_clist						*init_param(void)
{
	t_clist					*param;
	t_int					*content;
	int						x;

	x = 0;
	param = (t_clist *)malloc(sizeof(t_clist) * NB_PARAM);
	content = (t_int *)malloc(sizeof(t_int) * NB_INT);
	param->bit = content;
	while(x < NB_PARAM)
	{
		PARAM(x) = NULL;
		x++;
	}
	x = 0;
	while(x < NB_INT)
	{
		CONTENT(x) = 0;
		x++;
	}
	return (param);
}

char 						**read_standar(t_clist *param)
{
	char *line;
	char **tab;

	get_next_line(STDIN_FILENO, &line);
	PARAM(1) = line;
	tab = split_line(PARAM(1));
	PARAM(1) = tab;
	return(tab);
}

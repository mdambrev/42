/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 09:30:09 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/04 17:30:02 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

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

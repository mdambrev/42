/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 15:02:11 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/04 16:03:12 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_sh1.h"
# include <stdio.h>

t_content		*create_list(int nb_list)
{
	t_content	*axx;
	int			x;

	x = 0;
	axx = (t_content *)ft_memalloc(sizeof(t_content) * nb_list);
	while (x < nb_list)
	{
		add_l(&LIST_A(x), NULL, 0);
		x++;
	}
	return (axx);
}

int				search_occu(char *str, int c)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			break;
		i++;
	}
	return(i);
}

void			dup_env(char ** env, t_clist *param)
{
	t_content *axx;		
	int x;

	x = 0;
	axx = create_list(2);
	while(env[x])
	{
		add_l(&LIST_A(0), ft_strdup(env[x]), -1);
		x++;
	}
	LIST_R(0);
	PARAM(2) = LIST_A(0);
	while(LIST_IB(0, 0) == 0)
		VALUE_C(0,1) = ft_strsub(VALUE_C(0,0), 0, search_occu(VALUE_C(0, 0), '='));
	LIST_R(0);	
}


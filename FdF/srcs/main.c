/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 14:23:30 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/17 20:14:10 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//int  sub_main()

int main(int argc, char **argv)
{
	int nb_list;
	t_content *axx;
	int x;

	x = 0;

	nb_list = ft_nb_list(argc, argv);
	axx = parsing(argc, argv, nb_list);
	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:25:44 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/14 14:29:47 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"


int main(int argc, char **argv)
{
	t_content	*axx;
	int x;

	x = 1;
	if(argv[1] && argv[1][0] == '-')
	{
		if((x = set_option(argv[1])) == -1)
			return(0);
		argv++;
		argc--;
	}
	if(argc < 2)
		return(0);
	verif_error(argv++);
	axx = create_list(argv, argc);
	VALUE_I(2, 0) = x;

	tri_basic(axx);
	while(argc--)
		op(axx, 3);
	if(VALUE_I(2, 0) != 1)
	{
		if(x == 3)
			result(axx);
		printf("\n========================\n");
		printf("nb_coup = %zu\n", op(axx, -1));
	}
	return(0);
}

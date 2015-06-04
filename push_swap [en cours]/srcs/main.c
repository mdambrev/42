/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:25:44 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/04 04:59:24 by mdambrev         ###   ########.fr       */
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

	x = 0;
	if(argc < 2)
		return(0);
	verif_error(argv++);
	axx = create_list(argv, argc);
	VALUE_I(2, 0) = 2;

	//printf("\nA = %d || B = %d\n", VALUE_I(0, 0),VALUE_I(1, 0));
	test_sort(axx);
	printf("\nnb_coup = %zu\n", op(axx, -1));
/*	if(VALUE_I(2, 0) == 1)
	ft_putchar('\n');
	while(LIST_IB(0, 0) == 0)
		printf("%d\n", VALUE_I(0,0));
	printf("\n========================\n");
	while(LIST_IB(1, 0) == 0)
		printf("%d\n", VALUE_I(1,0));
	printf("nb_coup = %zu\n", op(axx, -1));*/
	return(0);
}

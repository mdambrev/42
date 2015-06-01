/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:25:44 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/01 07:35:51 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"


int main(int argc, char **argv)
{
	t_content	*axx;

	if(argc < 2)
		return(0);
	verif_error(argv++);
	axx = create_list(argv, argc);
	VALUE_I(2, 0) = 1;
	push_b(axx, 1);
	push_a(axx, -6);
	VALUE_I(2, 0) = 1;


	printf("\nA = %d || B = %d\n", VALUE_I(0, 0),VALUE_I(1, 0));
	ft_putchar('\n');

	while(LIST_IB(0, 0) == 0)
		printf("%d\n", VALUE_I(0,0));
	printf("\n========================\n");
	
	while(LIST_IB(1, 0) == 0)
		printf("%d\n", VALUE_I(1,0));
	return(0);
}

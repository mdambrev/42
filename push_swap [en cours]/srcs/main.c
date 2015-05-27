/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:25:44 by mdambrev          #+#    #+#             */
/*   Updated: 2015/05/27 15:51:51 by mdambrev         ###   ########.fr       */
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
	axx = create_list(argv);
	s_a(axx);
	p_b(axx);
	p_b(axx);
	p_b(axx);
	rr(axx);
	rrr(axx);
	s_a(axx);
	p_a(axx);
	p_a(axx);
	p_a(axx);


	while(LIST_IB(0, 0) == 0)
		printf("%d\n", VALUE_I(0,0));

	printf("\n========================\n");
		
	while(LIST_IB(1, 0) == 0)
		printf("%d\n", VALUE_I(1,0));

}

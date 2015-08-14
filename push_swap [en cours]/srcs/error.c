/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 11:01:25 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/14 13:45:51 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int verif_digits(char *str)
{
	int x;

	x = 0;
	if(str[0] == '-' && str[1] != '\0')
		str++;
	while(str[x])
	{
		if(ft_isdigit(str[x]) == 0)
		{
			ft_putendl("ERROR");
			exit(-1);
		}
		x++;
	}
	return(1);
}

static int ft_norm(char *str, int y)
{
	if (str[0] > '2')
		return (1);
	if (str[1] > '1')
		return (1);
	if (str[2] > '4')
		return (1);
	if (str[3] > '7')
		return (1);
	if (str[4] > '4')
		return (1);
	if (str[5] > '8')
		return (1);
	if (str[6] > '3')
		return (1);
	if (str[7] > '6')
		return (1);
	if (str[8] > '4')
		return (1);
	if (y == 1 && str[9] > '7')
		return (1);
	if (y == 2 && str[9] > '6')
		return (1);
	return(0);
}

int	verif_overflow(char *str)
{
	int x;
	int y;

	y = 1;
	if(str[0] == '-' && y++)
		str++;
	x = ft_strlen(str);
	if(x == 10)
	{
		if(ft_norm(str, y))
			return(1);
	}
	else if(x > 10)
		return(1);
	return(0);
}

void verif_error(char **argv)
{
	int x;
	int y;

	x = 0;
	y = 0;
	argv++;
	while(argv[x])
	{
		y = x + 1;
		if(verif_digits(argv[x])&& verif_overflow(argv[x]) == 1)
		{
				ft_putendl("ERROR");
				exit(-1);
		}
		while(argv[y])
		{
			if(ft_strequ(argv[x], argv[y]) == 1)
			{
				ft_putendl("ERROR");
				exit(-1);
			}
			y++;
		}
		x++;
	}
}

int	set_option(char *str)
{
	if((str[2] != '\0' || (str[1] != 't' && str[1] != 'v' && str[1] != 'r') 
		|| str[1] == '\0') && ft_isdigit(str[1]) != 1)
	{
		ft_putstr("Pushswap: illegal option ");
		ft_putendl(str);
		ft_putstr("usage: ./pushswap [-tv] [nb_list ...]\n");
		return(-1);
	}
	if(str[1] == 't')
		return(0);
	else if(str[1] == 'v')
		return(2);
	else if(str[1] == 'r')
		return(3);
	else 
		return(1);
}

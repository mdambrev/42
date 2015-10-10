/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/10 12:01:15 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/10 12:07:43 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/* cette fonction doit obligatoirement etre prototype de cette facon */ 
void	ft_sigint(int i)
{
	// insere ici le comportement desire lorsque le signal est capte
	write(1, "toto\n", 5);

	exit(2);
}

void	ft_signal(void)
{
	// premier parametre le signal desire
	// deuxieme parametre un pointeur sur fonction qui va gerer le signal desire
	signal(SIGINT, ft_sigint);

}

int main(void)
{
	ft_signal();
	// je peux placer une fonction qui va appeler les signal! 

	while (42)
	{
		write(1, "je suce des bites\n", 18); 
	}
	return (0);
}

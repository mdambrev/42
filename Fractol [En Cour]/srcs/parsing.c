/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 15:56:33 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/08 10:42:09 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fractol.h>

t_clist						*init_param(void)
{
	t_clist					*param;
	t_float					*content;

	param = (t_clist *)malloc(sizeof(t_clist) * NB_PARAM + 10);
	content = (t_float *)malloc(sizeof(t_float) * NB_INT + 10100);
	param->bit = content;
	free(PARAM(2));
	PARAM(2) = NULL;
	return (param);
}

void						put_list(void)
{
	ft_putendl("Liste des fractal disponible :");
	ft_putendl("-- Mandelbrot");
	ft_putendl("-- Julia");
	ft_putendl("-- Chromosome");
	exit(0);
}

void						write_param(int argc, char **argv, t_clist *param)
{
	if (argc != 2)
		put_list();
	if (ft_strequ(argv[1], "Mandelbrot"))
		CONTENT(0) = 1;
	else if (ft_strequ(argv[1], "Julia"))
		CONTENT(0) = 2;
	else if (ft_strequ(argv[1], "Chromosome"))
		CONTENT(0) = 3;
	else
		put_list();
}

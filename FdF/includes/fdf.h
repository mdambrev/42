/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:44:55 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/21 15:47:03 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define NB_INT 10
# define NB_PARAM 3 + 1
# define LARGEUR 1900
# define HAUTEUR 1080
# define CONTENT(x) ((t_int *)param->bit + x)->t_x
# define PARAM(x)	((t_clist *)param + 1 + x)->bit

#include "libft.h"
#include <stdio.h> // a suprimer
#include <unistd.h>
#include <mlx.h>
#include <get_next_line.h>
#include <fcntl.h>

void draw(t_content *axx, int nb_list);
t_content *parsing(int argc, char **argv, int nb_list);
int	ft_nb_list(int argc, char **argv);
int main_pos(t_content *axx, int nb_list);
void trace_map(t_content *axx, t_clist *param);
void projection_parallele(t_content *axx, int nb_list);
int set_color(t_clist *a, t_clist *b);
void tracer_bresenham(t_clist *param, t_clist *a, t_clist *b);

#endif

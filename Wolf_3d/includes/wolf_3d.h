/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 15:48:52 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/10 14:39:25 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# define NB_INT 10
# define NB_PARAM 3 + 1
# define LARGEUR 480
# define HAUTEUR 240
# define CONTENT(x) ((t_float *)param->bit + x)->t_x
# define PARAM(x)	((t_clist *)param + 1 + x)->bit
# include "libft.h"
# include <unistd.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <get_next_line.h>
# include <stdio.h>

typedef	struct			s_env;
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}						t_env;

t_content 			*parsing(int argc, char **argv, int nb_list);
void				draw(int argc, char **argv);
void				direction(t_clist *param, int keycode);
void				init_image(t_clist *param);
void				pixel_put(t_clist *param, int x, int y, int col);
int					main_pos(t_content *axx, int nb_list);
t_clist				*init_param(void);
int					ft_nb_list(int argc, char **argv);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 15:48:52 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/15 18:43:05 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# define NB_INT 100
# define NB_PARAM 100
# define LARGEUR 960
# define HAUTEUR 480
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
# include <math.h>

typedef	struct			s_env
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
	double	camera_x;
	double	ray_pos_x;
	double	ray_pos_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double 	side_dist_y;
	double	delta_dist_y;
	double	delta_dist_x;
	double		step_x;
	double		step_y;
	int		hit;
	int		side;
	double	perpwalldist;
	int 	draw_start;
	int 	draw_end;
	double 	line_height;
	int		up;
	int		down;
	int		left;
	int		right;
	int		rotate;
	int		rev_rotate;
	double	vit_marche;
	double	vit_rotate;
	double	old_dir_x;
	double	old_dir_y;
	double	old_plan_x;
	double	old_plan_y;
}						t_env;

t_content 			*parsing(int argc, char **argv, int nb_list);
void				draw(int argc, char **argv, t_content *axx, int nb_list);
void				direction(t_clist *param, int keycode);
void				init_image(t_clist *param);
void				pixel_put(t_clist *param, int x, int y, int col);
int					main_pos(t_content *axx, int nb_list);
t_clist				*init_param(void);
int					ft_nb_list(int argc, char **argv);
void				set_to_buffeur(t_clist *param, t_content *axx);
t_env				init_map(void);
void				init_calcul(t_clist *param, double x);
void				set_vector_value(t_clist *param);
void 				search_block(t_clist *param, t_content *axx);
void				correction_optique(t_clist *param);
void				set_hauteur(t_clist *param);
void				write_buffeur(t_clist *param, int x);
void				set_mouv(t_clist *param, t_content *axx);
int					boolean_mouv(t_clist *param, int keycode);
int					boolean_stop_mouv(t_clist *param, int keycode);
void				transform_map(t_content *axx, int  nb_list, t_clist *param);

#endif

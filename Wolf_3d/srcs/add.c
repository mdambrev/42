/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 14:26:23 by mdambrev          #+#    #+#             */
/*   Updated: 2015/09/24 20:37:06 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf_3d.h"

t_env init_map(void)
{
	t_env e;

	e.pos_x = 2;
	e.pos_y = 2;
	e.dir_x = -1;
	e.dir_y = 0;
	e.plan_x = 0;
	e.plan_y = 1;
	e.left = 0;
	e.right = 0;
	e.down = 0;
	e.up = 0;
	e.rotate = 0;
	e.rev_rotate = 0;
	e.vit_marche = 0.1;
	e.vit_rotate = 0.1;
	return(e);
}

void init_calcul(t_clist *param, double x)
{
	t_env *e;

	e = PARAM(5);
	e->camera_x = (2 * x / (double)(LARGEUR)) - 1;
	e->ray_pos_x = e->pos_x;
	e->ray_pos_y = e->pos_y;

	e->ray_dir_x = e->dir_x + e->plan_x * e->camera_x;
	e->ray_dir_y = e->dir_y + e->plan_y * e->camera_x;
	e->map_x = (int)e->ray_pos_x;
	e->map_y = (int)e->ray_pos_y;
	e->delta_dist_x = sqrt(1 + (e->ray_dir_y * e->ray_dir_y) / (e->ray_dir_x * e->ray_dir_x));
	e->delta_dist_y = sqrt(1 + (e->ray_dir_x * e->ray_dir_x) / (e->ray_dir_y * e->ray_dir_y));
	e->hit = 0;
}

void set_vector_value(t_clist *param)
{
	t_env *e;

	e = PARAM(5);
	if (e->ray_dir_x < 0)
	{
		e->step_x = -1;
		e->side_dist_x = (e->ray_pos_x - e->map_x) * e->delta_dist_x;
	}
   	else
	{
		e->step_x = 1;
		e->side_dist_x = (e->map_x + 1.0 - e->ray_pos_x) * e->delta_dist_x;
	}
	if (e->ray_dir_y < 0)
	{
		e->step_y = -1;
		e->side_dist_y = (e->ray_pos_y - e->map_y) * e->delta_dist_y;
	}
   	else
	{
		e->step_y = 1;
		e->side_dist_y = (e->map_y + 1.0 - e->ray_pos_y) * e->delta_dist_y;
	}
//	printf("step_y = %d, step_x = %d\n, ", e-> step_y, e-> step_x);
}

void search_block(t_clist *param, t_content *axx)
{
	t_env *e;

	(void)axx;
	e = PARAM(5);
	int **tab;
	
	tab = PARAM(6);
	while(e->hit == 0)
	{
		if (e->side_dist_x < e->side_dist_y)
   		{
			e->side_dist_x += e->delta_dist_x;
			e->map_x += e->step_x;
			e->side = 0;
		}
   		else
   		{
			e->side_dist_y += e->delta_dist_y;
			e->map_y += e->step_y;
			e->side = 1;
		}
	 	if (tab[e->map_y][e->map_x] > 0 ) 
		 	e->hit = 1; 
	}
	 if(e->side == 1 && e->pos_y > e->map_y)
		e->side = 2;

}

void correction_optique(t_clist *param)
{
	t_env *e;

	e = PARAM(5);
	if (e->side == 0)
		e->perpwalldist = fabs((e->map_x - e->ray_pos_x + (1 - e->step_x) / 2) / e->ray_dir_x);
	else
		e->perpwalldist = fabs((e->map_y - e->ray_pos_y + (1 - e->step_y) / 2) / e->ray_dir_y);
}

void set_hauteur(t_clist *param)
{
	t_env *e;

	e = PARAM(5);
	e->line_height = abs((int)(HAUTEUR / e->perpwalldist));
	e->draw_start = (-1 * ((e->line_height)) / 2 )+ (HAUTEUR / 2);
	if(e->draw_start < 0)
		e->draw_start = 0;	
	e->draw_end = (e->line_height / 2) + (HAUTEUR / 2);
	if(e->draw_end >= HAUTEUR)
		e->draw_end = HAUTEUR - 1;
}

void write_buffeur(t_clist *param , int x)
{
	int y;
	t_env *e;
	int color;

	e = PARAM(5);
	if(e->side == 0 && e->pos_x > e->map_x)
		color = 0xFFFF00;
	else if(e->side == 1)
		color = 0x00FF00;
	else if(e->side == 2)
		color = 0xFF0000;
	else if(e->side == 0 && e->pos_x < e->map_x)
		color = 0x0000FF;
//	else
//		color = 0xf2f2f2;
	y = e->draw_start;
//	printf("y = %d\n",y );
	while(y < e->draw_end)
	{
		pixel_put(param, y, x, color);
		y++;
	}
}

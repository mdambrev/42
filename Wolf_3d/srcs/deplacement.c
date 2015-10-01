/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 13:23:57 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/01 04:38:24 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf_3d.h"

int boolean_mouv(t_clist *param, int keycode)
{
	t_env *e;

	e = PARAM(5);
	if(keycode == 125)
		e->down = 1;
	else if(keycode == 126)
		e->up = 1;
	else if(keycode == 124)
		e->rotate = 1;
	else if(keycode == 123)
		e->rev_rotate = 1;
	else 
		return(0);
	return(1);
}

int boolean_stop_mouv(t_clist *param, int keycode)
{
	t_env *e;

	e = PARAM(5);
	if(keycode == 125)
		e->down = 0;
	else if(keycode == 126)
		e->up = 0;
	else if(keycode == 124)
		e->rotate = 0;
	else if(keycode == 123)
		e->rev_rotate = 0;
	else 
		return(0);
	return(1);
}


void set_rotate(t_clist *param)
{
	t_env *e;

	e = PARAM(5);
	e->vit_rotate = 0.000015;
	if (e->rotate == 1)
	{
		e->old_dir_x = e->dir_x;
		e->dir_x = e->dir_x * cos(-e->vit_rotate) - e->dir_y * sin(-e->vit_rotate);
		e->dir_y = e->old_dir_x * sin(-e->vit_rotate) + e->dir_y * cos(-e->vit_rotate);
		e->old_plan_x = e->plan_x;
		e->plan_x = e->plan_x * cos(-e->vit_rotate) - e->plan_y * sin(-e->vit_rotate);
		e->plan_y = e->old_plan_x * sin(-e->vit_rotate) + e->plan_y * cos(-e->vit_rotate);
	}
	if (e->rev_rotate == 1)
	{
		e->old_dir_x = e->dir_x;
		e->dir_x = e->dir_x * cos(e->vit_rotate) - e->dir_y * sin(e->vit_rotate);
		e->dir_y = e->old_dir_x * sin(e->vit_rotate) + e->dir_y * cos(e->vit_rotate);
		e->old_plan_x = e->plan_x;
		e->plan_x = e->plan_x * cos(e->vit_rotate) - e->plan_y * sin(e->vit_rotate);
		e->plan_y = e->old_plan_x * sin(e->vit_rotate) + e->plan_y * cos(e->vit_rotate);
	}

}

void	set_direction(t_content *axx, t_clist *param)
{
	(void)axx;
	(void)param;
	int **tab;
	t_env *e;

	e = PARAM(5);
	tab = PARAM(6);
	e->vit_marche = 0.000015;
	if (e->up == 1)
	{
		if((e->pos_x + e->dir_x * e->vit_marche) < CONTENT(5) - 1 && e->pos_x + e->dir_x * e->vit_marche > 1)
			e->pos_x += e->dir_x * e->vit_marche;
		if((e->pos_y + e->dir_y * e->vit_marche) < CONTENT(6) - 1 && e->pos_y + e->dir_y * e->vit_marche > 1)
			e->pos_y += e->dir_y * e->vit_marche;
	}

	if (e->down == 1)
	{			
	if((e->pos_x - e->dir_x * e->vit_marche) < CONTENT(5) - 1 && e->pos_x - e->dir_x * e->vit_marche > 1) 
			e->pos_x -= e->dir_x * e->vit_marche;
		if((e->pos_y - e->dir_y * e->vit_marche) < CONTENT(6) - 1&& e->pos_y - e->dir_y * e->vit_marche > 1)
			e->pos_y -= e->dir_y * e->vit_marche;
	}
}

void set_mouv(t_clist *param, t_content *axx)
{
	(void)axx;
	set_rotate(param);
	set_direction(axx, param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 00:01:14 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/08 12:43:58 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LIST_H

# define LIB_LIST_H
# define LIST_V(y, z) 	((axx + y)->list + z)->bit
# define LIST_A(y) 		(axx + y)->list
# define LIST_IB(y, z) 	(LIST_A(y) = LIST_V(y, z)) == LIST_V(y, 2)
# define LIST_IC(y, z) 	(LIST_V(y, z) != LIST_V(y, 2))
# define LIST_R(y) 		LIST_A(y) = LIST_V(y, 2)
# define LIST_I(y, z) 	(LIST_A(y) = LIST_V(y, z))
# define NB_CONTENT 	4
# define VALUE_I(y, z) 	((t_int*)VALUE_C(y, 0) + z)->t_x
# define VALUE_C(y, z) 	((axx + y)->list + z + 3)->bit
# define TMP_C(y, z)  	((axx + y + NB_LIST)->list + z + 3)->bit
# define TMP_I(y, z)	((t_int*)TMP_C(y, z))->t_x
# define TMP_V(y, z) 	((axx + y + NB_LIST)->list + z)->bit
# define TMP_A(y) 		(axx + y + NB_LIST)->list
# define NB_LIST 		3
# define NB_TMP			9
# define PUSH(y, z)    	TMP_A(y) = LIST_A(z)
# define PUSH2(y, z)	if((((PUSH(0, y)) ) && (PUSH(1, z))))
# define NORM(y, z)		((t_clist *)LIST_V(y, z) + 3)
# define VALUE_IN(y, z) ((t_int *)NORM(y, z)->bit)->t_x
# define NORM2(y, z)	((t_clist *) LIST_V(y + NB_LIST, z) + 3)
# define TMP_IN(y, z) 	((t_int *)NORM2(y, z)->bit)->t_x
# define VALUE_INC(y, z, x) ((t_int *)NORM3(y, z)->bit + x)->t_x
# define NORM3(y, z)		((t_clist *)LIST_V(y, z) + 3)
# define CONTENT(x) ((t_int *)param->bit + x)->t_x
# define PARAM(x)	((t_clist *)param + 1 + x)->bit


typedef	struct		s_clist
{
	void			*bit;
}					t_clist;

typedef	struct		s_content
{
	t_clist			*list;
}					t_content;

typedef	struct		s_int
{
	int				t_x;
}					t_int;

typedef	struct		s_float
{
	long double			t_x;
}					t_float;

void				add_content(t_clist **racine,
void				*content, t_clist **list);
t_clist				*init_racine(void);
void				push(t_content *axx, const char *list);
void				add_l(t_clist **list, void *src, int pos_x);
t_content			*init_list(void);
void				list_del(t_content *axx, int nb_list);
void				del_elem(t_content *axx, int n_list, int pos_x, int sens);
void				move_chain(t_content *axx, int pos_x, int pos_y);
void				sort_list_bul(t_content *axx,
int					nlist, int (*cmp)(int, int));
void				add_lstr(t_clist **list, int n_mail, int pos_x, void *src);
void				**list_to_tab(t_content *axx, int n_list, int type, int n_content);

#endif

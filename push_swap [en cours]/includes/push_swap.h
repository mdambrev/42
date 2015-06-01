/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 04:57:55 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/01 04:05:30 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

void 		verif_error(char **argv);
t_content 	*create_list(char **argv, int argc);
void		p_a(t_content *axx, int y);
void		p_b(t_content *axx, int y);
void		s_a(t_content *axx, int y);
void 		s_b(t_content *axx, int y);
void		r_a(t_content *axx, int y);
void		r_b(t_content *axx, int y);
void 		rr(t_content *axx, int y);
void		rra(t_content *axx, int y);
void		rrb(t_content *axx, int y);
void		rrr(t_content *axx, int y);
int			cmp(int a, int b);
int			check_list(t_content *axx);
void		ss(t_content *axx, int y);
int			op(t_content *axx, int x, int y);
void		push_a(t_content *axx, int pos_x);
void		push_b(t_content *axx, int pos_x);

#endif

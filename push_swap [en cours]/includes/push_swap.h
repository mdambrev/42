/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 04:57:55 by mdambrev          #+#    #+#             */
/*   Updated: 2015/05/28 18:04:32 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

void 		verif_error(char **argv);
t_content 	*create_list(char **argv);
void		p_a(t_content *axx);
void		p_b(t_content *axx);
void		s_a(t_content *axx);
void 		s_b(t_content *axx);
void		r_a(t_content *axx);
void		r_b(t_content *axx);
void 		rr(t_content *axx);
void		rra(t_content *axx);
void		rrb(t_content *axx);
void		rrr(t_content *axx);
int			cmp(int a, int b);
int			check_list(t_content *axx);

#endif

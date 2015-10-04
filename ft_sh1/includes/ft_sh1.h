/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 09:08:51 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/04 17:13:32 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H

# define FT_SH1_H
# include "get_next_line.h"

# define NB_PARAM 10
# define NB_INT 10

t_clist *init_param(void);
char	**read_standar(t_clist *param);
char 	**split_line(char const *s); 
void 	ret_bin(t_clist *param);
void	dup_env(char **env, t_clist *param);

# endif

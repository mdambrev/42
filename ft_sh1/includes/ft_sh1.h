/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 09:08:51 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/10 18:27:43 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H

# define FT_SH1_H
# include "get_next_line.h"

# define NB_PARAM 8
# define NB_INT 8

t_clist *init_param(void);
char	**read_standar(t_clist *param);
char 	**split_line(char const *s); 
int 	ret_bin(t_clist *param);
void	dup_env(char **env, t_clist *param);
void	set_action(t_clist *param, int order_tab);
int		set_builds(t_clist *param);
void	exec_builtins(t_clist *param);
void	ft_setenv(t_clist *param);
int		search_occu(char *str, int c);
void	ft_unsetenv(t_clist *param);
void	exec_bin(t_clist *param);
void	bin_bin(t_clist *param);
void	ft_cd(t_clist *param);
char	*search_home(t_clist *param);
int		set_old_pwd(t_clist *param, char *str);

# endif

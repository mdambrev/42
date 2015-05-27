/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 13:57:43 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:31:08 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# define MINORBITS			20
# define MINORMASK			((1U << MINORBITS) - 1)
# define MAJOR(dev)			((unsigned int) ((dev) >> (MINORBITS + 4)))
# define MINOR(dev)			((unsigned int) ((dev) & MINORMASK))

# include "libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <stdio.h>

t_list		*ls_(const char *flux, char const *option);
int			nb_option(int argc, char **argv);
void		ls_tri_main(t_list **list, char *option, char *flux);
void		ls_tri_t(t_list **list, char *flux, char *option);
void		ls_tri_a(t_list **list);
t_list		*stock_ls_(const char *flux, char const *option);
void		aff_ls_(t_list **tab, int size_tab, int argc, char **argv);
char		*option_ls(int argc, char **argv);
char		*join_option(char **tab, int y);
char		**args_ls(int argc, char **argv);
int			nb_path(int argc, char **argv);
char		*min_args(char **tab, int size);
char		**args_order(int argc, char **argv);
char		*del_dup(char *str);
char		*verif_option(char *str);
void		aff_list_(t_list *tab, int y, char *argv, char *option);
void		aff_all_list(t_list **tab, int argc, char **argv);
char		*option_main(int argc, char **argv);
t_list		**set_option(char *option, int argc, char **argv);
char		**test_args(int argc, char **argv);
int			nb_true_args(int argc, char **argv);
void		aff_list_r_(t_list *argv, char *option, char *bob);
void		aff_all_r_(t_list **tab, int argc, char **argv);
int			times_comp(char *str1, char *str2, char *flux, char *o);
void		concac_chaine(char *str, t_list **chain);
void		ls_tri_a_r(t_list **list);
t_list		*create_list_folder(int argc, char **argv);
void		print_folder(t_list *liste, int argc, char **argv);
int			test_files(char *flux, char *str);
void		main_file(int argc, char **argv, char *option);
void		set_file_option(t_list **list, char *option);
t_list		*create_list_error(int argc, char **argv);
void		print_error(t_list *liste);
int			test_error(char *flux);
void		main_error(int argc, char **argv, char *option);
void		set_error_option(t_list **list, char *option);
int			len_octet_max(t_list *liste, char *flux, int *z);
int			len_link_max(t_list *liste, char *flux);
void		parse_type(char **ret, char *flux);
char		*main_parse(char *flux);
void		parse_type(char **ret, char *flux);
void		parse_admin(char **ret, char *flux);
void		parse_group(char **ret, char *flux);
void		parse_user(char **ret, char *flux);
int			error_mod(char *flux);
void		aff_option(char *flux, char *content, char *option, t_list *tab);
void		aff_link(t_list *tab, char *content, char *flux);
void		aff_octet(t_list *tab, char *content, char *flux);
void		aff_user_grp(char *flux, char *content, t_list *tab);
void		aff_time(char *content);
char		*concac_flux(char *content, char *flux);
void		aff_total_l(t_list *liste, char *flux, char *option);
int			cmp_tmp(char *str);
void		aff_symb(char *flux, char *content);
int			cmp_name(t_list *tab, char *content);
int			cmp_grp(t_list *tab, char *content);
void		special_file(char *flux);
int			test_symb(char *flux, int argc, char **argv);
t_list		*list_symb(int argc, char **argv, char *option);
void		aff_user_link(char *str, int x, int y);
void		aff_list_link(t_list *liste);
void		aff_link2(t_list *tab, int x, int y, int z);
int			cmp_link(t_list *list, int y);
void		main_link(int argc, char **argv, char *option);
int			cmp_octet(t_list *liste);
void		put_octet(char *str, int z);
char		*aff_user(char *str);
char		*aff_grp(char *str);
size_t		debug_grp(char *str, size_t x);
size_t		debug_user(char *str, size_t x);
size_t		debug_link(char *str, size_t x);
size_t		debug_octet(char *str, size_t x, int *y);
t_list		*norm_t(t_list **list, char *option);
char		*ft_norm(char *str, char **add);

#endif

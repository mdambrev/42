/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 01:53:54 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 17:43:00 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*main_parse(char *flux)
{
	char			*ret;
	int				x;

	x = 0;
	ret = (char*)malloc(sizeof(char) * 12);
	ret[10] = '\0';
	while (x < 10)
		ret[x++] = '-';
	parse_type(&ret, flux);
	parse_admin(&ret, flux);
	parse_group(&ret, flux);
	parse_user(&ret, flux);
	return (ret);
}

void				parse_type(char **ret, char *flux)
{
	struct stat		buf;

	lstat(flux, &buf);
	if (S_ISDIR(buf.st_mode))
		ret[0][0] = 'd';
	else if (S_ISLNK(buf.st_mode))
		ret[0][0] = 'l';
	else if (S_ISSOCK(buf.st_mode))
		ret[0][0] = 's';
	else if (S_ISBLK(buf.st_mode))
		ret[0][0] = 'b';
	else if (S_ISCHR(buf.st_mode))
		ret[0][0] = 'c';
	else if (S_ISFIFO(buf.st_mode))
		ret[0][0] = 'p';
	else if (S_ISREG(buf.st_mode))
		ret[0][0] = '-';
	else
		ret[0][0] = '?';
}

void				parse_admin(char **ret, char *flux)
{
	struct stat		buf;

	lstat(flux, &buf);
	if (buf.st_mode & S_IRUSR)
		ret[0][1] = 'r';
	if (buf.st_mode & S_IWUSR)
		ret[0][2] = 'w';
	if (buf.st_mode & S_IXUSR)
		ret[0][3] = 'x';
}

void				parse_group(char **ret, char *flux)
{
	struct stat		buf;

	lstat(flux, &buf);
	if (buf.st_mode & S_IRGRP)
		ret[0][4] = 'r';
	if (buf.st_mode & S_IWGRP)
		ret[0][5] = 'w';
	if (buf.st_mode & S_IXGRP)
		ret[0][6] = 'x';
}

void				parse_user(char **ret, char *flux)
{
	struct stat		buf;

	lstat(flux, &buf);
	if (buf.st_mode & S_IROTH)
		ret[0][7] = 'r';
	if (buf.st_mode & S_IWOTH)
		ret[0][8] = 'w';
	if (buf.st_mode & S_IXOTH)
		ret[0][9] = 'x';
}

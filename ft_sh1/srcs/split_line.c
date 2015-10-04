/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 10:51:16 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/04 14:46:42 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_sh1.h>
#include <stdio.h>

static int	world(const char *s)
{
	int		x;
	int		i;

	x = 0;
	i = 0;
	while(s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	if(s[i])
		x++;
	while(s[i])
	{
		if(s[i] == '"')
				while(s[i] != '\0')
					if(s[++i] == '"')
						break;
		if(s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		{
			while(s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
				i++;
			if(s[i] == '\0')
				break;
			if(s[i] == '"')
				while(s[i] != '\0')
					if(s[++i] == '"')
						break;
			x++;
		}
		i++;
	}
	return (x);
}

int	world_len(const char *s)
{
	int		x;

	x = 0;
	while ((*s  == '\n' || *s  == '\t' || *s == ' '))
		s++;
	while (*s)
	{	
		if ((*s  == '\n' || *s  == '\t' || *s == ' '))
			break ;
		if(*s == '"')
			while(*s != '\0')
			{
				x++;
				s++;
				if(*s == '"')
					break;
			}
			x++;
			s++;
	}
	return (x);
}

char		**split_line(char const *s)
{
	char	**tab;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (s == NULL)
		return (NULL);
	if ((tab = (char **)malloc(1 + (sizeof(char *)) * world(s))) == NULL)
		return (NULL);
	while (	(*s  == '\n' || *s  == '\t' || *s == ' ')
)
		s++;
	while (*s)
	{
		if ((tab[x] = (char*)malloc(1 + ((world_len(s))))) == NULL)
			return (NULL);
		y = 0;
		while ((*s  != '\n' && *s  != '\t' && *s != ' ') && *s != '\0')
		{
			if(*s == '"')
			{
				while(*s != '\0')
				{
					tab[x][y++] = *s++;
					if(*s == '"')
						break;
				}
			}
			tab[x][y++] = *s++;
		}
		tab[x++][y] = '\0';
		while ((*s  == '\n' || *s  == '\t' || *s == ' ')
 && *s != '\0')
			s++;
	}
	tab[x] = 0;
	return (tab);
}

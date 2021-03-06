/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:32:19 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/01 20:15:30 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	int		x;
	char	*strdup2;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	x = ft_strlen(s);
	if ((strdup2 = (char *)malloc(sizeof(*strdup2) * (x + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		strdup2[i] = s[i];
		i++;
	}
	if (s)
	{
		strdup2[i] = '\0';
	}
	return (strdup2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 02:32:32 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/13 15:25:00 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	unsigned int	counter;

	counter = 0;
	if ((fresh = (char *)malloc(sizeof(fresh) * len + 1)) == NULL)
		return (NULL);
	if (!s)
		return (NULL);
	while (counter < len)
	{
		fresh[counter++] = s[start++];
	}
	fresh[counter] = '\0';
	return (fresh);
}
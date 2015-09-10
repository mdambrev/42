/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnews.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 03:37:33 by mdambrev          #+#    #+#             */
/*   Updated: 2015/04/19 18:30:25 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew_bin(size_t size)
{
	unsigned int	counter;
	char			*news;

	counter = 0;
	if ((news = (char *)malloc(sizeof(news) * size + 1)) == NULL)
		return (NULL);
	while (counter < size)
	{
		*(news + counter) = '0';
		counter++;
	}
	*(news + counter) = '\0';
	return (news);
}
